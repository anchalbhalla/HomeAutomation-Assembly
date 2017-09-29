import urllib2


try:
    urllib2.urlopen('http://google.com', timeout=1)
    print ("internet available")
    
except urllib2.URLError as err: 
    print ("Error")
   

