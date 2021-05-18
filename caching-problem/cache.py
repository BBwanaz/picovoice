
def caching(func):
"""Wrapper function to store database for quick access

This function uses a python dictionary as a cache. The dictionary is ordered
with the first element being the least recently used ISBN and the last element
being the most recently used ISBN.

:param func: function to be wrapped
:return: wrapped function
"""
	cache = dict()							# ordered cache. Least recently used (LRS) -> Most Recently Used (MRU)
	N = 20 									# max number of entries in cache probably declared in a .env file

	def wrapped_func(*args):
	"""This function implements a size N cache that uses LRU replacement policy.

	:param args: ISBN number passed as a parameter to func
	:return: book info
	"""
		if args in cache:					# if ISBN is in cache
			book_info = cache.pop(args)		# remove cache hit and store in book_info variable
			cache[args] = book_info			# move hit to the end (MRU)
			return book_info 				# return book info

		if len(cache) == N:					# if cache is full
			del cache[list(cache)[0]]   	# remove first element (LRU element)

		book_info = func(*args)				# call get_book_info(isbn)

		cache[args] = book_info 			# add book info to cache as MRU
		return book_info 					# return book info
	return wrapped_func
