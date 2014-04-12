/*
 * This file is part of Tocc. (see <http://www.github.com/aidin36/tocc>)
 * Copyright (C) 2013, 2014, Aidin Gharibnavaz <tocc@aidinhut.com>
 *
 * Tocc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tocc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with Tocc.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "utilities/cmd_parser.h"
#include "common/exceptions/cmd_usage_exceptions.h"

namespace tocccli
{

  /*
   * Parses command line parameters.
   *
   * @param argc: Count of parameters.
   * @param argv: Array of parameters.
   *
   * @return: A vector of options and their values. First element of the
   *   the internal vector is the option, and second element is its value.
   */
  std::vector<std::vector<std::string> > parse_cmd(int argc, char* argv[])
  {
    std::vector<std::vector<std::string> > result;

    // We started the loop from one, because zero is the name of the binary.
    for (int i = 1; i < argc; ++i)
    {
      if (argv[i][0] == '-')
      {
        // A new option.
        std::vector<std::string> single_option;

        single_option.push_back(argv[i]);
        single_option.push_back("");

        result.push_back(single_option);
      }
      else
      {
        if (result.empty())
        {
          throw new InvalidParametersError(
              "First parameter have to be an option (e.g. starts with a dash)");
        }

        if (result.back().back() != "")
        {
          result.back().back() += " ";
        }
        result.back().back() += argv[i];
      }
    }

    return result;
  }

}
