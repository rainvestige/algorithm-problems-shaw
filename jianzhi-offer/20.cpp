#include <iostream>

using namespace std;

class Solution {
public:
  enum class State {
    kStartSpace,
    kSign,
    kInteger,
    kNoDigitBeforeFloatPoint,
    kFloatPoint,
    kSignificant,
    kSignificantSign,
    kSignificantInteger,
    kEndSpace,
  };

  // Valid characters.
  // [' ', '+', '-', '[0-9]', '.', 'E', 'e']
  bool isNumber(string s) {
    State state = State::kStartSpace;
    for (char ch : s) {
      switch (state) {
        case State::kStartSpace:
          if (!ProcessStartSpace(state, ch)) {
            return false;
          }
          break;
        case State::kSign:
          if (!ProcessSign(state, ch)) {
            return false;
          }
          break;
        case State::kInteger:
          if (!ProcessInteger(state, ch)) {
            return false;
          }
          break;
        case State::kNoDigitBeforeFloatPoint:
          if (!ProcessNoDigitBeforeFloatPoint(state, ch)) {
            return false;
          }
          break;
        case State::kFloatPoint:
          if (!ProcessFloatPoint(state, ch)) {
            return false;
          }
          break;
        case State::kSignificant:
          if (!ProcessSignificant(state, ch)) {
            return false;
          }
          break;
        case State::kSignificantSign:
          if (!ProcessSignificantSign(state, ch)) {
            return false;
          }
          break;
        case State::kSignificantInteger:
          if (!ProcessSignificantInteger(state, ch)) {
            return false;
          }
          break;
        case State::kEndSpace:
          if (!ProcessEndSpace(state, ch)) {
            return false;
          }
          break;
        default:
          std::cout << "Something error happened!\n";
          break;
      }
    }
    if (state == State::kEndSpace || state == State::kSignificantInteger ||
        state == State::kFloatPoint || state == State::kInteger) {
      return true;
    } else {
      return false;
    }
  }

  bool ProcessStartSpace(State& state, char ch) {
    switch (ch) {
      case ' ':
        // No need to change state.
        break;
      case '+':
      case '-':
        // Sign.
        state = State::kSign;
        cout << "StartSpace -> Sign\n";
        break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        state = State::kInteger;
        cout << "StartSpace -> Integer\n";
        break;
      case '.':
        state = State::kNoDigitBeforeFloatPoint;
        cout << "StartSpace -> NoDigitBeforeFloatPoint\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessSign(State& state, char ch)
  {
    switch (ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        state = State::kInteger;
        cout << "Sign -> Integer\n";
        break;
      case '.':
        state = State::kNoDigitBeforeFloatPoint;
        cout << "Sign -> NoDigitBeforeFloatPoint\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessInteger(State& state, char ch)
  {
    switch (ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        // state = State::kInteger;
        break;
      case '.':
        state = State::kFloatPoint;
        cout << "Integer -> FloatPoint\n";
        break;
      case 'e':
      case 'E':
        state = State::kSignificant;
        cout << "Integer -> Significant\n";
        break;
      case ' ':
        state = State::kEndSpace;
        cout << "Integer -> EndSpace\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessNoDigitBeforeFloatPoint(State& state, char ch)
  {
    if (isdigit(ch)) {
      state = State::kFloatPoint;
      cout << "NoDigitBeforeFloatPoint -> FloatPoint\n";
      return true;
    } else {
      return false;
    }
  }

  bool ProcessFloatPoint(State& state, char ch)
  {
    switch (ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        // state = State::kFloatPoint;
        break;
      case 'e':
      case 'E':
        state = State::kSignificant;
        cout << "FloatPoint -> Significant\n";
        break;
      case ' ':
        state = State::kEndSpace;
        cout << "FloatPoint -> EndSpace\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessSignificant(State& state, char ch)
  {
    switch (ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        state = State::kSignificantInteger;
        cout << "Significant -> SignificantInteger\n";
        break;
      case '+':
      case '-':
        state = State::kSignificantSign;
        cout << "Significant -> SignificantSign\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessSignificantSign(State& state, char ch)
  {
    switch (ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        state = State::kSignificantInteger;
        cout << "Significant -> SignificantInteger\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessSignificantInteger(State& state, char ch)
  {
    switch (ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        // state = State::kSignificantInteger;
        break;
      case ' ':
        state = State::kEndSpace;
        cout << "SignificantInteger -> EndSpace\n";
        break;
      default:
        return false;
    }
    return true;
  }

  bool ProcessEndSpace(State& state, char ch)
  {
    switch (ch) {
      case ' ':
        state = State::kEndSpace;
        break;
      default:
        return false;
    }
    return true;
  }
};
