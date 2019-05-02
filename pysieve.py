#!/usr/bin/env python3

class Sieve:
    def __init__(self, max):
        self.max = max
        self.primes = [True for _ in range(max+1)]
        self.next_prime = 1
    
    def find_next_prime(self):
        self.next_prime += 1
        while (self.next_prime <= self.max) and \
                (not self.primes[self.next_prime]):
            self.next_prime += 1
    
    def filter_nums(self):
        idx = self.next_prime ** 2
        while idx <= self.max:
            self.primes[idx] = False
            idx += self.next_prime
    
    def sum_primes(self):
        sum = 0
        while True:
            self.find_next_prime()
            if self.next_prime > self.max:
                return sum
            sum += self.next_prime
            self.filter_nums()

print(Sieve(2000000).sum_primes())