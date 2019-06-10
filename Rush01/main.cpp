/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 23:12:45 by cjulliar          #+#    #+#             */
/*   Updated: 2019/06/02 23:12:46 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.hpp"
#include <iostream>

int	main(int argc, char const *argv[]) {

    if (argc == 1 || (argc == 2 && std::string(argv[1]) == "gui")) {
            Monitor monitor(true);
            monitor.display();
    } else if (argc == 2 && std::string(argv[1]) == "ncurses") {
            Monitor monitor;
            monitor.display();
    } else {
            std::cout << "usage: " << argv[0] << " [ncurses | gui]" << std::endl;
    }

	return EXIT_SUCCESS;
}
