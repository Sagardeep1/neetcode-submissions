class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.beginNode = Node(-1, -1)
        self.endNode = Node(-2, -2)
        self.hashMap = {}
        self.beginNode.next, self.endNode.prev = self.endNode, self.beginNode

    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev
    
    def insert(self, node):
        prev, nxt = self.endNode.prev, self.endNode
        prev.next, nxt.prev = node, node
        node.prev, node.next = prev, nxt
    
    def get(self, key: int) -> int:
        if key in self.hashMap:
            node = self.hashMap[key]
            self.remove(node)
            self.insert(node)
            return self.hashMap[key].val
        
        else:
            return -1
            

    def put(self, key: int, value: int) -> None:
        if key in self.hashMap:
            self.remove(self.hashMap[key])
        node = Node(key, value)
        self.insert(node)
        self.hashMap[key] = node
        if len(self.hashMap) > self.capacity:
            node = self.beginNode.next
            self.remove(node)
            del self.hashMap[node.key]
            del node
        


        
