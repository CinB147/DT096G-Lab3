#include <iostream>

template<int From, int To, int Using, int N>
struct Hanoi {
    typedef Hanoi<From, Using, To, N-1> prev_move;
    typedef Hanoi<Using, To, From, N-1> next_move;

    static void exec() {
        prev_move::exec(); // Move N-1 disks to the auxiliary rod.
        std::cout << "Move disk from " << From << " to " << To << std::endl;
        next_move::exec(); // Move N-1 disks to the destination rod.
    }
};

// Base case recursion
template<int From, int To, int Using>
struct Hanoi<From, To, Using, 0> {
    static void exec() {
    }
};

template<int N>
struct Run {
    static void exec() {
        Hanoi<1, 3, 2, N>::exec(); // 1 (source), 3 (destination), 2 (auxiliary)
    }
};

int main()
{
    Run<5>::exec();
    return 0;
}