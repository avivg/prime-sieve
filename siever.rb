#!/usr/bin/env ruby

class Sieve
  def initialize(max)
    @max = max
    @primes = (0..max).map {true}
    @next_prime = 1
  end

  def find_next_prime
    @next_prime += 1
    while @next_prime <= @max && (not @primes[@next_prime])
      @next_prime += 1
    end
  end
  
  def filter_nums
    idx = @next_prime ** 2
    while idx <= @max do
      @primes[idx] = false
      idx += @next_prime
    end
  end

  def sum_primes
    sum = 0
    while true
      find_next_prime
      if @next_prime > @max
        return sum
      end
      sum += @next_prime
      filter_nums
    end
  end
end

puts Sieve.new(2000000).sum_primes
