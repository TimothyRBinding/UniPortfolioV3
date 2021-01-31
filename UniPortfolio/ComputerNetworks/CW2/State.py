class State:
    state = None #abstract class
    CurrentContext = None
    def __init__(self, Context):
        self.CurrentContext = Context

class StateContext:
    stateIndex = 0;
    CurrentState = None
    availableStates =[]
    #availableStates = ["CLOSED", "LISTEN", "SYNSENT", "SYNRECVD", "ESTABLISHED", "FINWAIT1", "CLOSEWAIT", "FINWAIT2", "TIMEDWAIT", "LASTACK",]

    def setState(self, newstate):
        self.CurrentState = self.availableStates[newstate]
        self.stateIndex = newstate

    def getStateIndex(self):
        return self.stateIndex

'''
States key:
    CLOSED = 0
    LISTEN = 1
    SYNSENT = 2
    SYNRECVD = 3
    ESTABLISHED = 4
    FINWAIT1 = 5
    CLOSEWAIT = 6
    FINDWAIT2 = 7
    TIMEDWAIT = 8
    LASTACK = 9
'''
