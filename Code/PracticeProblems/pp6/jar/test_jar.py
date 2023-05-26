from jar import Jar

def test_init():
    jar = Jar()
    assert jar.capacity == 12 
    jar2 = Jar(3)
    assert jar2.capacity == 3
    
def test_str():
    jar = Jar()
    assert str(jar) == ''
    
def test_deposit():
    jar = Jar()
    jar.deposit(6)
    assert jar.size == 6
    jar.deposit(2)
    assert jar.size == 8
    
def test_withdraw():
    jar = Jar()
    jar.deposit(6)
    jar.withdraw(1)
    assert jar.size == 5
    
# To run the tests: 
## pytest test_jar.py