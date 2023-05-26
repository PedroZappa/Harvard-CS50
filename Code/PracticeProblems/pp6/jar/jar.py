def main():
    jar = Jar()
    jar.deposit(10)
    jar.withdraw(5)
    print(jar)
    
    # Testing
    test_init(jar)


class Jar:
    def __init__(self, capacity=12):
        # if capacity != non-negative integer: raise ValueError()
        if capacity < 0:
            raise ValueError("Capacity has to be a positive integer.")
        # Initialize a jar with a given capacity
        self._capacity = capacity
        self._size = 0 # Start with an empty jar

    # Defined in a way that is easy to read and outputs all the members of the class
    def __str__(self):
        # Return a str with n 🍪, n = 🍪 in the jar
        return self.size * '🍪'

    def deposit(self, n):
        # if adding n to the jar would exceed capacity: raise ValueError()
        if n > self.capacity:
            raise ValueError("Trying to add too many cookies. Jar is full!")
        if self.size + n > self.capacity:
            raise ValueError("Trying to add too many cookies. Jar is full!")
        # Add n 🍪 in the jar
        self._size += n

    def withdraw(self, n):
        # if n is larger than #🍪 in the jar: raise ValueError()
        if self.size < n:
            raise ValueError(f"Not enough cookies in the jar to withdraw {n} 🍪.")
        # Remove n 🍪 from the jar
        self._size -= n

    @property
    def capacity(self):
        # return the capacity of the jar
        return self._capacity

    @property
    def size(self):
        # return the # 🍪 in the jar
        return self._size
    ...

# Run
main()

