#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>

int main() {
  std::string seqpa, seq;
  printf("digite uma sequencia (PA apenas), separado por virgulas.\n>");
  std::getline(std::cin, seqpa);

  while(!std::cin.good() || std::regex_match(seqpa, std::regex("^[A-Za-z]+$"))) {
    std::cin.clear();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printf("Wrong syntax. (1,2,3,4 or 1, 2, 3, 4)\n>");
    std::getline(std::cin, seqpa);
  }

  // while (std::regex_match(seqpa, std::regex("^[A-Za-z]+$"))) {
  //   printf("Wrong syntax. (1,2,3,4 or 1, 2, 3, 4)\n>");
  //   std::getline(std::cin, seqpa);
  // }
  
  seqpa.erase(std::remove(seqpa.begin(), seqpa.end(), ' '), seqpa.end());
  std::stringstream ss(seqpa);

  int numbers[] = {};
  int j = 0;
  
  while(getline(ss, seq, ',')) {
    numbers[j] = std::stoi(seq);
    // std::cout << seq << std::endl;
    j++;
  }

  int numbersLength = j;
  
  if (numbersLength < 2) {
    printf("digite pelo menos dois números na sequência.\n");
    return 0;
  }

  int r = numbers[1] - numbers[0];

  printf("\nPA calculada, escolha o termo que deseja visualizar da sequencia.\n>");

  std::cin.clear();

  while (true) {
    std::string ns;
    int n;
    std::cin >> ns;
    while(!std::cin.good()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      printf("Não é permitido utilizar letras.\n>");
      std::getline(std::cin, ns);
    }
    std::stringstream nss(ns);
    nss >> n;
    std::cout << n << std::endl;
    int an = numbers[0] + (n - 1) * r;
    printf("O %i termo é igual a %i de razão r=%i\n>", n, an, r);
  }
}
