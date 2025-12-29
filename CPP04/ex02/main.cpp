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

int main()
{
  Animal *meta = new Dog();
  Animal *meta1 = new Cat();
  // Animal animal;

	Dog dog("how");
	Cat cat("Meo");
	Dog dog1(dog);
	Cat cat1;
	cat1 = cat;

  meta->makeSound();
  meta1->makeSound();
  dog.makeSound();
	std::cout << dog1.getType() << std::endl;
	std::cout << cat1.getType() << std::endl;

  delete(meta);
  delete(meta1);

	return 0;
}
