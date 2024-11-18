# Python Functions

## Docstrings
```
""" This is a docstring """
```

It can be accessed with `<functionName>.__doc__` or `help(functionName)`

## Nested functions
You can write functions like this
```
def multiplier(facotr):
    def multiplyByFactor(number):
        return number * factor
    return multiplyByFactor
```