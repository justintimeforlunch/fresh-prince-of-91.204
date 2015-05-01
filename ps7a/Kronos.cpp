// Copyright [2015] Justin Nguyen

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>

using boost::gregorian::date;
using boost::gregorian::years;
using boost::gregorian::months;
using boost::gregorian::days;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_duration;
using boost::gregorian::date_period;
using boost::posix_time::ptime;
using boost::posix_time::hours;
using boost::posix_time::minutes;
using boost::posix_time::seconds;
using boost::posix_time::time_duration;

int main(int argc, char* argv[]) {
  std::ifstream logFile(argv[1]);
  std::string fileName = argv[1];
  std::ofstream rptFile(fileName + ".rpt", std::ofstream::out);
  std::string line;
  date _d;
  ptime _tStart;
  if (argc != 2) {
    throw std::runtime_error("Usage: enter one log file");
  } else {
    bool boot = false;
    int lineNum = 1;
    boost::regex e_begin_boot(
      "([0-9]+)-([0-9]+)-([0-9]+) "
      "([0-9]+):([0-9]+):([0-9]+): "
      "\\(log.c.166\\) server started.*");
    boost::regex e_end_boot(
      "([0-9]+)-([0-9]+)-([0-9]+) "
      "([0-9]+):([0-9]+):([0-9]+).([0-9]+):INFO:"
      "oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*");
    if (logFile.is_open()) {
      while (getline(logFile, line)) {
        boost::smatch m;
        if (regex_match(line, m, e_begin_boot)) {
          date _tempDate(stoi(m[1]), stoi(m[2]), stoi(m[3]));
          _d = (_tempDate);
          ptime _tempStart(_d,
                           time_duration(stoi(m[4]), stoi(m[5]), stoi(m[6])));
          _tStart = _tempStart;
          if (boot) {
            rptFile << "**** Incomplete boot ****\n" << std::endl;
            boot = false;
          }
          rptFile << "=== Device boot ===\n"
                  << lineNum << "(" << argv[1] << "): "
                  << m[1] << "-" << m[2] << "-" << m[3]
                  << " "
                  << m[4] << ":" << m[5] << ":" << m[6]
                  << " Boot Start" << std::endl;
          boot = true;
        } else if (regex_match(line, m, e_end_boot)) {
          date _tempDateFinish(stoi(m[1]), stoi(m[2]), stoi(m[3]));
          ptime _tEnd(_tempDateFinish,
                      time_duration(stoi(m[4]), stoi(m[5]), stoi(m[6])));
          rptFile << lineNum << "(" << argv[1] << "): "
                  << m[1] << "-" << m[2] << "-" << m[3]
                  << " "
                  << m[4] << ":" << m[5] << ":" << m[6]
                  << " Boot Completed" << std::endl;
          time_duration _td = _tEnd - _tStart;
          int _bootTime = _td.total_milliseconds();
          rptFile << "    "
                  << "Boot Time: " << _bootTime << "ms\n" << std::endl;
          boot = false;
        }
        lineNum++;
      }
      rptFile.close();
      logFile.close();
    } else {
      throw std::runtime_error("Cannot open file");
    }
  }
  return 0;
}
