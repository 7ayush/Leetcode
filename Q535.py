import base64
class Codec:
    def __init__(self):
        self.urls = []
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        curr_ind = str(len(self.urls))
        encode = base64.b64encode(bytes(curr_ind,'utf-8'))
        self.urls.append(longUrl)
        return "http://tinyurl.com/"+encode.decode('utf-8')
        
    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        short = shortUrl[19:]
        curr_ind = base64.b64decode(short)
        return self.urls[int(curr_ind)]
