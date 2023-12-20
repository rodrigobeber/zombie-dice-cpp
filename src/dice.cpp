#include "dice.h"
#include "gen.h"

Dice::Dice(const std::initializer_list<double>& probabilities) : m_dis(probabilities) {}

DiceFace Dice::roll() {
    return static_cast<DiceFace>(m_dis(gen));
}

std::string diceFaceToString(DiceFace face) {
    switch (face) {
        case DiceFace::Brain:
            return "BRAIN";
        case DiceFace::Footsteps:
            return "FOOTSTEP";
        case DiceFace::Shotgun:
            return "SHOTGUN";
        default:
            return "Unknown";
    }
}

GreenDice::GreenDice() : Dice({3, 1, 2}) {
}

RedDice::RedDice() : Dice({1, 2, 3}) {
}

YellowDice::YellowDice() : Dice({2, 2, 2}) {
}

std::string GreenDice::getColorName() const {
    return "GREEN";
}

std::string RedDice::getColorName() const {
    return "RED";
}

std::string YellowDice::getColorName() const {
    return "YELLOW";
}
