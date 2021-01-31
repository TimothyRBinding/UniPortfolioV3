# -*- coding: cp1252 -*-
'''
Title: ImplementationOfDijkstrasAlgorithm.py
Name: Tim Binding
Description:
    Programme to show how dijkstras algorithm works using a graph map to work with.
    The programme requires a network map in the form of a textfile to be passed through
    the populate_network function and a text file with the route for the algorithm in
    parse_route to start and end at e.g. A>F. The programme assumes that their are no
    negative weighted vertices and that their will be no routes inputted that are not
    letters and are in the formant of: C>A or B>F.
    '''
infinity = 1000000
invalid_node = -1

'''
Node class:
    This node class will be the bases for all nodes, every node in the network
    graph will have a distance from the source value, a visited boolean and the
    ability to check the previous node or set the current node to previous node.
'''
class Node:
    previous = invalid_node
    distfromsource = infinity
    visited = False

'''
Dijkstra class:
    The dijkstra class contains all of the functions that are required to find
    the shortest path to a node in a graph. This programme takes in a textfile
    that represents a graph of nodes and assigning them default values checks
    all unvisited nodes from the current node and then calculate the tentative
    distance from source.

    In this class several functions take in files from the programme it is
    important to remember for each one of these files to make sure that every
    file that is opened is closed.
'''
class Dijkstra:
    '''Function initialise class:
        The initialise class declares all of the primary variables, lists and
        booleans values that will be used across the dijkstra class and all of
        its functions. Start node and end node will be set as the points that
        the shortest path algorithm will start and end at.
    '''
    def __init__(self):
        '''initialise class'''
        self.startnode = 0
        self.endnode = 0
        self.network = []
        self.network_populated = False
        self.nodetable = []
        self.nodetable_populated = False
        self.route = []
        self.route_populated = False
        self.currentnode = 0
        
    '''
    Function populate_network:
        The populate_network function takes in a file, the texts file can be
        named anything but in order for will be in the form of a table, each row
        and column will represent the nodes in a graph starting from a in the top
        right and expands outward and the numbers will represent each edges cost
        to one another.

        The network[] list is going to be a list of all of the nodes in the
        network.
    '''
    def populate_network(self, filename):
        '''populate network data structure'''
        self.network_populated = False
        try:
            networkfile = open(filename, "r")
        except IOError:
            print "Network file does not exist!"
            return
        for line in networkfile:
            self.network.append(map(int, line.strip().split(',')))
        self.network_populated = True
        networkfile.close()
        
    '''
    Function populate_node_table:
        populate_node_table function is for adding each node from the network (which
        was populated in the populate_network function) to the nodetable.

        Nodetable is set to empty to prevent adding nodes on top of nodes that might
        be already be contained inside.

        The start node distance from source and visited are set to 0 and false
        this is because the start node is the source so it would naturally be
        zero and the nodes boolean of visited will change to True when the
        calculate_shortest_path function is called after it, this leaves the act
        of setting the nodes visited state to the calculate_shortest_path
        avoiding any confliction.

        nodetable[] list will hold the data of each nodes previous node,
        distance from source and whether or not its visited.
    '''
    def populate_node_table(self):
        '''populate node table'''
        self.nodetable_populated = False
        self.nodetable = []
        if not self.network_populated:
            print "Network not populated!"
            return
        for node in self.network:
            self.nodetable.append(Node())
        self.nodetable[self.startnode].distfromsource = 0
        self.nodetable[self.startnode].visited = False
        self.nodetable_populated = True
        
    '''
    Function parse_route:
        parse_route passes in a text file that will contain the route that the
        network starts from and its eventual destination.
        
        Start node and end node are converted from letters into numbers using
        the ord() function to return an integer based on ascii.

        The route[] list will take in a text file that will state the start node
        and end node.

        If the route is A>C then the output will be: [2, 0, 3, 4, 6].
    '''
    def parse_route(self, filename):
        '''load in route file'''
        self.route_populated = False
        self.route = []
        try:
            routefile = open(filename, "r")
        except IOError:
            print "Route file does not exist!"
            return
        for line in routefile:
            self.route = map(str, line.strip().split('>'))
            
        self.startnode = ord(self.route[0]) - 65
        self.endnode = ord(self.route[1]) - 65

        self.route_populated = True
        routefile.close()

    '''
    Function return_near_neighbour:
        Creates a list called 'nn' which is short for 'nearest neighbour'.

        A for loop is used to go though each neighbour to determine all of the
        neighbours of the current node.
        
        When enumerate is used on the network list by the index of the current
        node, each edge will be assigned a number based on its position in the
        list this will help when the loop is active it will go through each edge
        in the node and check if they have been visited and they are greater
        than zero this is because if the weight is greater than zero then that
        means that the is an weighted which means their is definitely a path.

        The 'nn' list will have all of the edges (which are columns in the
        graph map) in a node (row on the graph map) appended to it using
        a loop as long as it hasn�t been visited.
        
        Returns the node that is closest to the current node and has not been
        visited.

        This function will be used in calculate_tentative to compare all of the
        nearest neighbours.
    '''
    def return_near_neighbour(self):
        '''determine nearest neighbours of current node'''
        nn = []
        for index, edge in enumerate(self.network[self.currentnode]):
            if edge > 0 and not self.nodetable[index].visited:
                nn.append(index)
        return nn

    '''
    Function calculate_tentative:
        This function starts of by getting neighbours using the
        return_near_neighbour and then saving them as a list.

        For every neighbour that is in the 'nn' list, the programme will find
        the 'tentativedist' value is a variable that is used to find the tentative
        distance from edge being checked this is done by adding the current
        nodes distance with the nearest neighbour edge that is currently being
        checked.
        
        The if statement will check if the tentative distance value is less than
        the next nodes distance to source.
        
            If that is the case then the distance from source value of the
            nearest neighbour will be set to the tentative distance value that
            was calculated earlier.
            
            The node previous to the current neighbour index being checked
            will be set to current node.
    '''
    def calculate_tentative(self):
        '''calculate tentative distances of nearest neighbours'''
        nn = self.return_near_neighbour()
        for neighbourindex in nn:
            tentativedist = self.nodetable[self.currentnode].distfromsource + self.network[self.currentnode][neighbourindex]
            
            if tentativedist < self.nodetable[neighbourindex].distfromsource:
                self.nodetable[neighbourindex].distfromsource = tentativedist
                self.nodetable[neighbourindex].previous = self.currentnode

    '''
    Function determine_next_node:
        The 'bestdistance' value is set to infinity and the current node is set
        to invalid_node. The reason that it is done is to prepare to check through
        each node in the node table.

        for all of the nodes in 'nodetable':
        
            If the distance from the current node that is being checked distance to
            the start node is less than the 'bestdistance' value and the node being
            checked is not been visited yet.
            
                Then change the 'bestdistance' to the
                nodes distance from source.

                The current node will then be changed to the 'nodeindex' value this
                makes it the next node.
    '''
    def determine_next_node(self):
        '''determine next node to examine'''
        bestdistance = infinity
        self.currentnode = invalid_node
        for nodeindex,node in enumerate(self.nodetable):
            if(node.distfromsource < bestdistance) and node.visited == False:
                bestdistance = node.distfromsource
                self.currentnode = nodeindex

    '''
    Function calculate_shortest_path:
        Current node is set to the start node as the current node will be used to
        drive the programme forward and search for the shortest path.

        Temporary shortest path list will first take in the start node.

        while the current node is not the same value as the end node and current node
        is not -1 (invalid_node).
        
            Set the currentnode in the nodetable to be a visited node.
            
            Call the calculate_tentative to find the nearest neighbour with the least
            path cost.
            
            Then call determine_next_node to find the next node that needs to be
            evaluated.
    '''
    def calculate_shortest_path(self):
        '''calculate shortest path across network'''
        if self.network_populated and self.route_populated and self.nodetable_populated:
            self.currentnode = self.startnode
            
            while self.currentnode != self.endnode and self.currentnode != invalid_node:
                self.nodetable[self.currentnode].visited = True;
                self.calculate_tentative()
                self.determine_next_node()

            if self.currentnode == invalid_node:
                print "No path available"
                return False
            else:
                return True
        else:
            print "Error files not loaded in correctly"
            return False

    '''
    Fuction return_shortest_path:
        return_shortest_path gives back the shortest path in a list of ordered
        characters and the distance.

        This function gets the list from shortest path and then adds 65 to get 
        the character equivilant in ascii.
        
        Total distance is obtained getting the distance from the source at the
        end node.

        This gives back the path list in letters and beside it the total distance
        from the source to the end node.

        If the route is 'C>G' then return value will be:
        (['C', 'A', 'D', 'E', 'G'], 11).
    '''
    def return_shortest_path(self):
        '''return shortest path as list (start->end), and total distance'''
        if self.network_populated and self.route_populated and self.nodetable_populated:
            sp = []
            totaldistance = 0
            returnshortestpath = ""

            self.currentnode = self.endnode
            sp.append(self.endnode)
            
            if (self.calculate_shortest_path()):
                while not self.nodetable[self.currentnode].previous == invalid_node:
                    self.currentnode = self.nodetable[self.currentnode].previous
                    sp.append(self.currentnode)
             
                sp = sp[::-1]
                
                totaldistance = self.nodetable[self.endnode].distfromsource
                returnshortestpath = [chr(node + 65) for node in sp]
                    
                return returnshortestpath, totaldistance
            else:
                return False
        else:
            print "Error files not loaded in correctly"
            return False

if __name__ == '__main__':
            Algorithm = Dijkstra()
            Algorithm.populate_network("network.txt")
            Algorithm.parse_route("route.txt")
            Algorithm.populate_node_table()
            print Algorithm.return_shortest_path()
