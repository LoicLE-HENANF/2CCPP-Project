//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_ISTATE_H
#define INC_2CCPP_PROJECT_ISTATE_H

class IState {
public:
    IState()= default;;
    virtual ~IState()= default;

    // Basic IState methods
    virtual void OnEntry() = 0;
    virtual void OnExit() = 0;
};

#endif //INC_2CCPP_PROJECT_ISTATE_H
