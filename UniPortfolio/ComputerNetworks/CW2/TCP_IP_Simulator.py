'''
Created by: TCP_IP_Simulator.py

Description:
    This programme is a TCP IP Simulator. The server programme used so that clients are able to connect.
    This programme is an intergrated server and client so all is need is to use a command line interfaces find the
    directory of the file and type in two separate command line interfaces the lines below:
    TCP_IP_Simulator.py server
    TCP_IP_Simulator.py client

    self.CurrentContext.connection.recv(1024) - Server's way of recieving data
    self.CurrentContext.socket.recv(1024) - Client's way of recieving data

    The client programme will load a text file named client_commands
    A set of if statement's are given that are able to excute a series of actions
'''

from sys import argv
from time import sleep
import socket
import time

class State:
    CurrentContext = None
    def __init__(self, Context):
        self.CurrentContext = Context

    def trigger(self):
        return True

class StateContext:
    state = None
    CurrentState = None
    availableStates = {}

    def setState(self, newstate):
        try:
            self.CurrentState = self.availableStates[newstate]
            self.state = newstate
            self.CurrentState.trigger()
            return True
        except KeyError:
            return False

    def getStateIndex(self):
        return self.state

'''
Transistion class:
    The transition class is responsible for being the middle man between states.
    this classes functions never should be used, these will only be called if their is a problem between states.
'''

class Transition:
    def passive_open(self):
        print ("Error: Calling 'passive_open' has resulted in an error")
        return False
    def syn(self):
        print ("Error: Calling 'syn' has resulted in an error")
        return False
    def ack(self):
        print ("Error: Calling 'ack' has resulted in an error")
        return False
    def rst(self):
        print ("Error: Calling 'rst' has resulted in an error")
        return False
    def syn_ack(self):
        print ("Error: Calling 'syn_ack' has resulted in an error")
        return False
    def close(self):
        print ("Error: Calling 'close' has resulted in an error")
        return False
    def fin(self):
        print ("Error: Calling 'fin' has resulted in an error")
        return False
    def timeout(self):
        print ("Error: Calling 'timeout' has resulted in an error")
        return False
    def active_open(self):
        print ("Error: Calling 'active_open' has resulted in an error")
        return False

class Closed(State, Transition):
    '''
    Closed class:
        The closed class is a grounding state for the network.
        This state is the state that represents closed on a TCPIP technique.
        If the state is triggered then reset connection settings.
        
        Server:
            Passive open function will be used to create an open connection
            If anything recieved then reset
                Change to 'LISTEN' state
            
        Client:
            If connection with the sever has been opened (active opened):
                then send a synchronize (or sequence number) message
                and change state to 'SYN SENT'

            Reseting function that will reset all of the variables back to normal
            
    '''
    def __init__(self, Context): 
        State.__init__(self, Context)

    def passive_open(self):
        print ("Server: Passive open")
        # responsible for starting the process of listening for a connection
        self.CurrentContext.serverListen()
        print "Server: CLOSED state Transitioning to LISTEN state"
        self.CurrentContext.setState("LISTEN")
        return True

    def rst(self):
        if self.CurrentContext.socket != None:
            print ("Client: Resetting communications")
            self.CurrentContext.socket.close()
            self.CurrentContext.connection_address = 0
        else:
            print ("Server: Resetting communications")
            self.CurrentContext.connection.close()
        return True
    
    def active_open(self):
        self.CurrentContext.clientConnect()

        print ("Client: Sending SYN")
        self.CurrentContext.socket.send("SYN")
        print "Client: Transitioning to SYNSENT state"
        self.CurrentContext.setState("SYNSENT")
        return True

    def trigger(self):
        print "Current state: Closed"
        try:
            self.rst()
        except:
            pass

        return True

class Listen(State, Transition):
    '''
        Listen class:
            The listen state is where the server listens for any attempts by the client to make connections.

            Server:
                If Sequence number has been recieved
                    then send a sequence number and an acknowledgement message
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def syn_ack(self):
        print ("Server: Sending SYNACK")
        self.CurrentContext.connection.send("SYNACK")
        print "Current state: LISTEN state transitioning to SYNRECVD"
        self.CurrentContext.setState("SYNRECVD")
        return True

    def trigger(self):
       print "Current state: Listen"
       command = self.CurrentContext.connection.recv(1024)
       if command == "SYN" or command == "syn" or command == "Syn":
           self.CurrentContext.syn_ack()
       else:
           print "Error: Synchronize message not recieved"
           print "Initiating timeout"
           self.CurrentContext.connection.send("TIMEOUT")
       return True

class SynRecvd(State, Transition):
    '''
    SynRecvd class:
        Syn Recieved is where the server recieves a synchronize message from the client
        and a synack response has already been sent with an ack message on its way back
 
        Server:
            If acknowledgememnt message has been recieved
                then change state to "ESTABLISHED"
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def trigger(self):
        print "Current state: SynRecvd state"
        command = self.CurrentContext.connection.recv(1024)
        if command == "ACK" or command == "ack" or command == "Ack":
            print "Current state: LISTEN state transitioning to ESTABLISHED"
            self.CurrentContext.setState("ESTABLISHED")
        return True

class SynSent(State, Transition):
    '''
        SynSent class:
            This state is for when synchronize message has been sent by this client programme
            and what actions to take next including sending an acknowledgment back to the
            server letting them know that the data is transmitting to thier side correctly.
            
            If reset commuications event has been recieved:
                then do nothing
                and activate timeout function

            If Timeout event has been recieved:
                then reset communications
                and move on to activate timeout functionality

            If synchronize and acknowledgment message have been recieved:
                then send acknowledgement event back to the server
                and change states to 'ESTABLISHED'
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def rst(self):
        print "Current state: SynSent state transitioning to CLOSED"
        self.CurrentContext.setState("CLOSED")
        return True

    def ack(self):
        print "Client: ACK sent"
        self.CurrentContext.socket.send("ACK")
        print "Client: Sending ACK"
        self.CurrentContext.setState("ESTABLISHED")
        return True

    def timeout(self):
        print "Initiating timeout..."
        self.CurrentContext.socket.send("RST")
        print "Server: Sending RST"
        print "Current state: SynSent state transitioning to CLOSED"
        self.CurrentContext.setState("CLOSED")
        return True

    def trigger(self):
        print "Current state: SynSent state"
        
        command = self.CurrentContext.socket.recv(1024)

        if command == "TIMEOUT" or command == "Timeout" or command == "timeout":
            self.timeout()
        elif command == "SYNACK" or command == "SynAck" or command == "synack":
            self.ack()
        else:
            self.rst()
        return True
        
class Established(State, Transition):
    '''
    Established class:
        By this state the client and the server have finished the three way handshake.
        and their for are fully capable of safely sending and recieving data packests.

        A close function can be called by the user to begin the closing process of the connection
    
        Server:
            If fin event recieved from the client
                then send an acknowledgement to the client

        Client:
            This state is where client will be able to access the infomation and data provided by the server through access
            If close event has been recieved:
                then activate finish event
                and change states to 'FINWAIT1'
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def close(self):
        self.CurrentContext.socket.send("FIN")
        print ("Client: Sending FIN")
        print "Current state: ESTABLISHED state transitioning to FINWAIT1"
        self.CurrentContext.setState("FINWAIT1")
        return True
        
    def fin(self):
        command = self.CurrentContext.connection.recv(1024)
        if command == "FIN":
            self.CurrentContext.connection.send("ACK")
            print ("Server: Sending ACK")
            print "Current state: ESTABLISHED state transitioning to CLOSEWAIT"
            self.CurrentContext.setState("CLOSEWAIT")
        return True
    
    def trigger(self):
        print "Current state: Established state"
        
        try:
            self.CurrentContext.fin()
        except:
            self.CurrentContext.close()
        return True

class FinWait1(State, Transition):
    '''
    FinWait1 class:
        Fin wait class is to allow time for the server to recieve the fin message
        telling the server that the client would like to close the connection.
        
        Client:
            If acknowledgement message recieved:
                then do nothing
                and change state to "FINWAIT2"
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def trigger(self):
        print "Current state: FinWait1 state"

        command = self.CurrentContext.socket.recv(1024)
        
        if command == "ACK" or command == "Ack" or command == "ack":
            print "Current state: FINWAIT1 state transitioning to FINWAIT2"
            self.CurrentContext.setState("FINWAIT2")
        return True

class FinWait2(State, Transition):
    '''
    FinWait2 class:
        A second fin wait is used to wait for achknowledgement of the FIN message
    
        Client:
            If finish event recieved:
                then send acknowledgment
                and change state to "TIMEDWAIT"
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def ack(self):
        self.CurrentContext.socket.send("ACK")
        print "Client: sending ACK"
        print "Current state: FINWAIT2 state transitioning to TIMEDWAIT"
        self.CurrentContext.setState("TIMEDWAIT")
        return True

    def trigger(self):
        print "Current state: FinWait2 state"
        command = self.CurrentContext.socket.recv(1024)

        if command == "FIN" or command == "Fin" or command == "fin":
            self.ack()
        return True

class CloseWait(State, Transition):
    '''
    CloseWait class:
        This class will wait for the close call the reach before continuing
        
        Server:
            If close event has been fired
                then send a fin to the client
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def fin(self):
        self.CurrentContext.connection.send("FIN")
        print "Server: Sending FIN"
        print "Current state: CLOSEWAIT2 state transitioning to LASTACK"
        self.CurrentContext.setState("LASTACK")
        return False

    def trigger(self):
        print "Current state: CloseWait state"
        self.CurrentContext.fin()

class TimedWait(State, Transition):
    '''
    TimedWait class:
        The client will wait for the server to send a last acknowledgement to insure that the connection is closed up.
    
        Client:
            According to TCP/IP Illustrated Volume 1, the point of the TIMEWAIT is so that the final acknowledgment is not lost,
            if the fin is lost then a resending of the requests will occur until an acknowledgement is recieved

            Timeout occurs after the spesified setting

            Gives time to the server to recieve the acknowledgement
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def timeout(self):
        print "Initiating timeout..."
        self.CurrentContext.setState("CLOSED")
        return True

    def trigger(self):
        self.CurrentContext.timeout()
        return True

class LastAck(State, Transition):
    '''
    LastAck class:
        The last ack is the final stage in the four way termination model of TCP/IP.

        Server:
            Once the server recieves the last acknowledgement message from the client
                then activate timeout
    '''
    def __init__(self, Context):
        State.__init__(self, Context)

    def trigger(self):
        print "Current state: LastAck state"

        command = self.CurrentContext.connection.recv(1024)

        if command == "ACK" or command == "Ack" or command == "ack":
            self.CurrentContext.setState("CLOSED")
            return True

class TCPPeer(StateContext, Transition):
    '''
    TCP peer:
        This the class that allows the programme to be abstractly managed.
    '''
    def __init__(self):
        self.host = "127.0.0.1"
        self.port = 5000
        self.connection_address = 0
        self.connection = None
        self.socket = None
        self.commandList = []
    
        self.availableStates["CLOSED"] = Closed(self)
        self.availableStates["LISTEN"] = Listen(self)
        self.availableStates["SYNRECVD"] = SynRecvd(self)
        self.availableStates["SYNSENT"] = SynSent(self)
        self.availableStates["ESTABLISHED"] = Established(self)
        self.availableStates["FINWAIT1"] = FinWait1(self)
        self.availableStates["FINWAIT2"] = FinWait2(self)
        self.availableStates["CLOSEWAIT"] = CloseWait(self)
        self.availableStates["TIMEDWAIT"] = TimedWait(self)
        self.availableStates["LASTACK"] = LastAck(self)
        self.setState("CLOSED")
        
    def passive_open(self):
        return self.CurrentState.passive_open()
    
    def syn(self):
        return self.CurrentState.syn()

    def ack(self):
        return self.CurrentState.ack()

    def rst(self):
        return self.CurrentState.rst()
    
    def syn_ack(self):
        return self.CurrentState.syn_ack()
    
    def close(self):
        return self.CurrentState.close()
    
    def fin(self):
        return self.CurrentState.fin()
    
    def timeout(self):
        return self.CurrentState.timeout()
    
    def active_open(self):
        return self.CurrentState.active_open()

    '''
    serverListen function:
        Sets up the listening socket and allows for connections to join.
        This function is used in the passive_open function.
        This function should only be used in server mode.
    '''

    def serverListen(self):
        self.socket = socket.socket()
        try:
            print "Server: Ready for connection with client/s"
            self.socket.bind((self.host, self.port))
            self.socket.listen(1)
            self.connection, self.connection_address = self.socket.accept()
            return True
        except Exception as err: 
            print err
            exit()

    '''
    clientConnect function:
        This method is used in the 'active_open()'
        This method is used by the client to connect to a server.
        This function should only be used in Client mode.
    '''
    def clientConnect(self):
        self.socket = socket.socket()
        try:
            print "Client: Searching for a server to connect with"
            self.socket.connect((self.host, self.port))
            self.connection_address = self.host
            return True
        except Exception as err:
            print err
            exit()
        
    def loadClientCommands(self, filename):
        self.commands_loaded = False
        try:
            commandfile = open(filename, "r")
        except IOError:
            print filename + " cannot be found!"
            return False
        for command in commandfile:
            self.commandList.append(command)
        self.commands_loaded = True
        commandfile.close()

if __name__ == "__main__":
    if len(argv) < 2:
        print "Error: too few arguments"
        exit()

    if argv[1] == "server":
        TCPServer = TCPPeer()
        TCPServer.passive_open()
    else:
        TCPClient = TCPPeer()
        TCPClient.loadClientCommands("client_commands.txt") #Loads text file
        #Below is a for loop that is able to check the commands and act upon them
        for command in TCPClient.commandList:
            if command == "ACTIVE_OPEN":
                TCPClient.active_open()
            elif command == "SYN":
                TCPClient.syn()
            elif command == "ACK":
                TCPClient.ack()
            elif command == "SYNACK":
                TCPClient.syn_ack()
            elif command == "RST":
                TCPClient.rst()
            elif command == "TIMEOUT":
                TCPClient.timeout()
            elif command == "FIN":
                TCPClient.fin()
            elif command == "CLOSE":
                TCPClient.close()
            else:
                print ("Error: Command not recongized")

        #If you don't have client_command.txt uncomment this line below:
        #TCPClient.active_open()
