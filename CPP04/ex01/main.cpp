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
	Animal* animals[100];
  for (int i = 0; i < 100; i++)
  {
    if (i < 50)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }
  animals[4]->makeSound();
  animals[60]->makeSound();

  for (int i = 0; i < 100; i++)
  {
    delete animals[i];
  }
  Animal animal("ANIMAL");
  Cat obj("abdellah");
  Cat obj2("alll");
  // Brain brain;
  // for (int i = 0; i < 100; i++)
  // {
  //   brain.ideas[i] = "new Idea";
  // }
  obj2 = obj;

  Dog ob("abdellah");
  Dog ob2(ob);
	return 0;
}
