/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:00:55 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:22:17 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria { 
public:
	Cure();
	Cure(const Cure &other);
	Cure operator=(const Cure &other);
	~Cure();

	void cure(const std::string);
	AMateria* clone() const;
};
