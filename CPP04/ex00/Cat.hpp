/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:13:23 by asyani            #+#    #+#             */
/*   Updated: 2025/12/15 19:47:54 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

};
