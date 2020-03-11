
/*
 * MenuItem.cpp
 *
 *  Created on: 1.2.2016
 *      Author: krl
 */

#include "HomeScreen.h"
#include <cstdio>
#include <stdio.h>
#include <string.h>

HomeScreen::HomeScreen(LiquidCrystal *lcd_, Fan *fan_, Pressure *pressure_, ModeEdit *mode_) :
    lcd(lcd_),
    fan(fan_),
    pressure(pressure_),
    mode(mode_)
{
}

/* void HomeScreen::display() */
/* { */
/*     printf("test1\n"); */
/*     lcd->clear(); */
/*     printf("test2\n"); */
/*     displayTitles(); */
/*     printf("test3\n"); */
/*     displayFan(); */
/*     printf("test4\n"); */
/*     displayMode(); */
/*     printf("test5\n"); */
/*     displayPressure(); */
/* } */

void HomeScreen::display()
{
    lcd->clear();
    // First row
    lcd->setCursor(0, 0);
    char buffer[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, "%-6s%-5s%-5s", getModeTitle(), getFanTitle(), getPressureTitle());
    lcd->print(buffer);

    // Second row
    char fanString[BUF_SIZE] = "";
    char pressureString[BUF_SIZE] = "";
    sprintf(fanString, "%u", 10);
    sprintf(pressureString, "%d", 20);
    /* sprintf(fanString, "%u", fan->getSpeed()); */
    /* sprintf(pressureString, "%d", pressure->getPressure()); */
    strcat(fanString, "%%");
    strcat(pressureString, "pa");

    lcd->setCursor(0, 1);
    // second padding value has to one greater here compared to row above
    // because escaping % with "%%" eats one character from the padding
    snprintf(buffer, BUF_SIZE, "%-6s%-6s%-5s",
             mode->toString(mode->getValue()),
             fanString,
             pressureString);
    lcd->print(buffer);
}

void HomeScreen::displayTitles() {
    // First row
    lcd->setCursor(0, 0);
    char buffer[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, "%-6s%-5s%-5s", getModeTitle(), getFanTitle(), getPressureTitle());
    lcd->print(buffer);
}

void HomeScreen::displayMode() {
    lcd->setCursor(0, 1);
    char buffer[7] = "";
    snprintf(buffer, 7, "%-6s", mode->toString(mode->getValue()));
    lcd->print(buffer);
}

void HomeScreen::displayFan() {
    lcd->setCursor(6, 1);
    char buffer[7] = "";
    sprintf(buffer, "%u", fan->getSpeed());
    strcat(buffer, "%%");

    snprintf(buffer, 7, "%-6s", buffer);
    lcd->print(buffer);
}

void HomeScreen::displayPressure() {
    lcd->setCursor(11, 1);
    char buffer[7] = "";
    sprintf(buffer, "%u", pressure->getPressure());
    strcat(buffer, "pa");

    snprintf(buffer, 7, "%-5s", buffer);
    lcd->print(buffer);
}

void HomeScreen::event(menuEvent e)
{
    switch (e) {
        case ok:
            mode->changeState();
            break;
        case show:
            display();
            break;
        default:
            break;
    }
}
