#include <stdio.h>
#include <cmath>
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

  float numbers[] = {};
  int j = 0;
  
  while(getline(ss, seq, ',')) {
    numbers[j] = std::stof(seq);
    j++;
  }
  
  int numbersLength = j;
  
  if (numbersLength <= 2) {
    printf("digite pelo menos três números na sequência.\n");
    return 0;
  }

  if (numbersLength > 2) {
    float r;
    float r1 = numbers[1] - numbers[0];
    float r2 = numbers[2] - numbers[1];
    int rr1, rr2;
    bool isPA, validSequence, rIsReal;
    
    if (r1 == r2) {
      r = r1;
      isPA = true;
      validSequence = true;
    } else {
      //razão
      for (int i=0; i<numbersLength-2; i++) {
	r1 = numbers[i+1] / numbers[i];
	r2 = numbers[i+2] / numbers[i+1];
	
	rr1 = static_cast<int>(numbers[i+1]) % static_cast<int>(numbers[i]);
	rr2 = static_cast<int>(numbers[i+2]) % static_cast<int>(numbers[i+1]);

	if (r1 == r2) {
	  r = r1;
	  isPA = false;
	  validSequence = true;
	  if (rr1 == 0 && rr2 == 0) {
	    rIsReal = false;
	  } else {
	    rIsReal = true;
	  }
	} else {
	  validSequence = false;
	}
      }
    }

    std::cin.clear();
    // printf("PA? %d, sequencia valida? %d, r=%i, r não é um número inteiro? %d", isPA, validSequence, r, rIsReal);

    if (!validSequence) {
      printf("A sequência acima é impossível e não tem uma razão congruente.\n");
      std::exit(1);
    }
    
    while (true) {
      std::string ns;
      int n;
      printf("Digite o termo que quer que eu descubra./n>");
      std::cin >> ns;
      while(!std::cin.good()) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	printf("Não é permitido utilizar letras.\n>");
	std::getline(std::cin, ns);
      }
      std::stringstream nss(ns);
      nss >> n;
      // std::cout << n << std::endl;
      float an;
      if (isPA) {
	an = numbers[0] + (n - 1) * r;
	printf("O %i termo é igual a %.4f de razão r=%.0f\n", n, an, r);
      } else {
	an = numbers[0] * std::pow(r, n-1);
	printf("O %i termo é igual a %.4f de razão q=%.4f, (%.0f de resto %i)\n", n, an, r, std::round(r), rr1);
      }
      // printf("O %i termo é igual a %i de razão r=%f\n>", n, an, r);
    }
  }

//   int r = numbers[1] - numbers[0];

//   printf("\nPA calculada, escolha o termo que deseja visualizar da sequencia.\n>");

//   std::cin.clear();

//   while (true) {
//     std::string ns;
//     int n;
//     std::cin >> ns;
//     while(!std::cin.good()) {
//       std::cin.clear();
//       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//       printf("Não é permitido utilizar letras.\n>");
//       std::getline(std::cin, ns);
//     }
//     std::stringstream nss(ns);
//     nss >> n;
//     std::cout << n << std::endl;
//     int an = numbers[0] + (n - 1) * r;
//     printf("O %i termo é igual a %i de razão r=%i\n>", n, an, r);
//   }
}
