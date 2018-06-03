#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "classes/math.hpp"

TEST(SumTest, TwoPlusOne) {
	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	EXPECT_EQ(3, sum(2, 1));
}

TEST(SumTest, TwoPlusTwo) {
	EXPECT_EQ(4, sum(2, 2));
}