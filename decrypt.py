#submitted by : Animesh karmakar
#Purpose:  To get  Paid Internship Opportunity On Machine Learning & Blockchain in Circle FinTech 
#Date : 11 sep, 19

#Explanation: 
#      1. decrypt function take two arguments, one is encrypted code and other is encryption password.
#      2. first generate the private key using the password with hashlib module and SHA256 algorithm
#      3. decode with base64 module
#      4. generate an 16 bytes initialization vector (iv) 
#      5. generate a cipher using private_key and iv, decrypt with AES
#      6. unpad the decrypted text

import base64
import hashlib
from Crypto.Cipher import AES

# one-liner to sufficiently unpad the text to be decrypted
unpad = lambda s: s[:-ord(s[len(s) - 1:])]

def decrypt(enc, password):
	private_key = hashlib.sha256(password.encode("utf-8")).digest()
	enc = base64.b64decode(enc)
	iv = enc[:16]
	cipher = AES.new(private_key, AES.MODE_CBC, iv)
	return unpad(cipher.decrypt(enc[16:]))


password = 'a1b2c3d4e5f6g7h8'
enc = b'3Jgrnid0Y+JrqsxpWZ0q3w3UqpH6GEy4Fh27thLMUM0A82fHf2D6sl7AboKFcyOA'
dec = decrypt(enc, password)
print(dec)

