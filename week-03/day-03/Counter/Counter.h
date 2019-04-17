//
// Created by megha on 2019. 04. 17..
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter(int original);
    int a;

    Counter();

    int getOriginal() const;

    void adder(int);
    void add();
    int get();
    void reset();

private:
    int _original;
};


#endif //COUNTER_COUNTER_H
