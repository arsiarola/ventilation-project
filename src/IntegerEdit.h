/*
 * IntegerEdit.h
 *
 *  Created on: 2.2.2016
 *      Author: krl
 */

#ifndef INTEGEREDIT_H_
#define INTEGEREDIT_H_

#include "PropertyEdit.h"
#include "LiquidCrystal.h"
#include <string>

class IntegerEdit: public PropertyEdit {
public:
    IntegerEdit(LiquidCrystal *lcd_, std::string editTitle, int min_, int max_, int step_);
    virtual ~IntegerEdit();
    bool increment();
    bool decrement();
    void accept();
    void cancel();
    void setFocus(bool focus);
    bool getFocus();
    void display();
    int getValue();
    int getEdit();
    void setValue(int value);
    std::string getTitle();
private:
    void save();
    void displayEditValue();
    LiquidCrystal *lcd;
    std::string title;
    int value;
    int edit;
    bool focus;
    int min;
    int max;
    int step;
};

#endif /* INTEGEREDIT_H_ */
