/**
 * @file replace.cc
 * @author Mikra Selene (mikraselene@gmail.com)
 * @brief 我不会处理转义...
 * @version 0.1
 * @date --
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <fstream>
#include <iostream>

std::string rpl(std::string k, std::string s, std::string p) {
  while (s.find("  ") != s.npos) {
    s = s.replace(s.find("  "), 2, "");
  }
  while (s.find(k) != s.npos) {
    s = s.replace(s.find(k), k.size(), p);
  }
  return s;
}

int main() {
  std::string s;
  std::string input_file = "xml/dblp.xml";
  std::ifstream in(input_file);
  std::ofstream out("xml/ndblp.xml");
  int64_t cnt = 0;
  while (getline(in, s)) {
    cnt++;
    if (cnt % 100000 == 0) {
      std::cout << cnt / 100000 << std::endl;
    }
    s = rpl("&", s, "@");
    s = rpl("notetype", s, "note type");
    out << s;
  }
}
