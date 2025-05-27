#pragma once
#include "Vector.h"
#include "event.h"

class Dialog : public Vector {
public:
    Dialog() : Vector() { EndState = 0; }
    virtual ~Dialog() {}

    virtual void GetEvent(TEvent& event) {
        string s; char code;
        cout << '>';
        cin >> s;
        if (s.empty()) {
            event.what = evNothing;
            return;
        }
        code = s[0];
        event.what = evMessage;
        switch (code) {
            case 'm': event.command = cmMake; break;
            case '+': event.command = cmAdd; break;
            case '-': event.command = cmDel; break;
            case 's': event.command = cmShow; break;
            case '?': event.command = cmGet; break;
            case 'q': event.command = cmQuit; break;
            default: event.what = evNothing; break;
        }
        if (code == 'm' || code == '?') {
            string param = s.substr(1);
            event.a = atoi(param.c_str());
        }
    }

    int Execute() {
        TEvent event;
        do {
            EndState = 0;
            GetEvent(event);
            HandleEvent(event);
        } while (!Valid());
        return EndState;
    }
    int Valid() { return EndState != 0; }
    void ClearEvent(TEvent& event) { event.what = evNothing; }
    void EndExec() { EndState = 1; }

    void HandleEvent(TEvent& event) {
        if (event.what != evMessage) return;
        switch (event.command) {
            case cmMake:
                if (beg) delete[] beg;
                size = event.a;
                beg = new Object*[size];
                cur = 0;
                ClearEvent(event);
                break;
            case cmAdd: {
                if (cur < size) {
                    Student* s = new Student();
                    s->Input();
                    Add(s);
                }
                ClearEvent(event);
                break;
            }
            case cmDel:
                Del();
                ClearEvent(event);
                break;
            case cmShow:
                Show();
                ClearEvent(event);
                break;
            case cmGet:
                if (event.a >= 0 && event.a < cur) {
                    beg[event.a]->Show();
                } else {
                    cout << "Invalid index\n";
                }
                ClearEvent(event);
                break;
            case cmQuit:
                EndExec();
                ClearEvent(event);
                break;
            default:
                Vector::HandleEvent(event);
                break;
        }
    }

protected:
    int EndState;
};
