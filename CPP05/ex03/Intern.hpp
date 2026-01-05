#pragma once


#include <iostream>

class AForm;

/**
 * @class Intern
 * @brief Factory class responsible for creating AForm instances.
 *
 * The Intern class acts as a form factory. It reduces the workload of
 * bureaucrats by creating forms based on a given form name and target.
 *
 * ROLE:
 *  - Implements the makeForm() method.
 *  - Matches the given form name against known form types.
 *  - Creates and returns a pointer to the corresponding AForm if found.
 *  - Returns nullptr (or throws an exception) if the form name is unknown.
 */
class Intern {
  public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string form, std::string target);
};
