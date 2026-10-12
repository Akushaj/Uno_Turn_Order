//
// Created by AkshajKri on 10/11/26.
//
#pragma once
#include <iostream>
#include <string>

class Card {
public:
     Card(const std::string& color, const std::string& rank)
         :color_(color),rank_(rank){}

    friend std::ostream& operator<<(std::ostream& out, const Card& c) {
         return out << c.color_ << " " << c.rank_;
     }

private:
    std::string color_;
    std::string rank_;
};