/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:03:35 by asyani            #+#    #+#             */
/*   Updated: 2025/12/21 16:21:45 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &other);
	Ice operator=(const Ice &other);
	~Ice();

	void ice(const std::string);
	AMateria* clone() const;
};
