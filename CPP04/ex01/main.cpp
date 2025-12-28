/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:38:16 by asyani            #+#    #+#             */
/*   Updated: 2025/12/18 22:14:52 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
  Animal* animals[10];
  for (int i = 0; i < 10; i++)
  {
    if (i < 5)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }
  animals[1]->makeSound();
  animals[6]->makeSound();
  for (int i = 0; i < 10; i++)
  {
    delete animals[i];
  }

  std::cout << "------------- test deep copy ------------------" << std::endl;

  Cat cat1;
  cat1.getBrain()->ideas[0] = "I love fish";

  Cat cat2 = cat1;
  cat2.getBrain()->ideas[0] = "I love birds";

  std::cout << "Cat 1 idea: " << cat1.getBrain()->ideas[0] << std::endl;
  std::cout << "Cat 2 idea: " << cat2.getBrain()->ideas[0] << std::endl;
  cat1 = cat2;
  std::cout << "Cat 1 idea: " << cat1.getBrain()->ideas[0] << std::endl;
  std::cout << "Cat 2 idea: " << cat2.getBrain()->ideas[0] << std::endl;

  return 0;
}
