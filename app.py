import requests
from datetime import datetime
from sys import argv

# fn: 3->"hello", 5->"read", 6->"write"
# n: the number of times the request is made
# k: the argument passed to the serverless function (number of loops within that function)
def time_lambda(fn, n, k):
	times = []
	for i in range(n):
		before = datetime.now()
		url = "https://us-central1-elated-bebop-218613.cloudfunctions.net/function-%d?n=%d" % (fn, k)
		r = requests.get(url)
		after = datetime.now()
		res = r.text
		sc = r.status_code
		time_diff = (after-before).total_seconds() * 1000
		times.append((i, res, sc, time_diff))
	return times

# Calls hello(1) once
def hello_1():
	return time_lambda(3,1,1)

if __name__ == '__main__':
	res = hello_1()
	print(res)
