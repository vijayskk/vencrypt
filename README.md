# vencrypt
## A Simple File Encryption Tool

vencrypt is a C program that allows you to encrypt and decrypt files using a user-provided password. It offers a basic level of encryption for educational purposes. You can use the ```vencrypt.h``` header to implement this in your project also.

## Features:

- Encrypts and decrypts files using a password.
- Supports both encryption and decryption modes.
- Provides clear command-line options for ease of use.

*Important Note:*

*This program utilizes a rudimentary encryption technique and should not be considered secure for sensitive data. For robust encryption, explore industry-standard libraries or algorithms.*

## Usage:

### Cloning:

```bash
git clone https://github.com/vijayskk/vencrypt.git 
cd vencrypt
```

### Compiling:

```bash
gcc vencrypt.c -o vencrypt
```

### Encryption:

```bash
./vencrypt E <input_file> <output_file> <password>
```

Replace <input_file> with the path to the file you want to encrypt.
Replace <output_file> with the desired name for the encrypted file.
Replace <password> with the password.

### Decryption:

```bash
./vencrypt D <input_file> <output_file> <password>
```

Replace <input_file> with the path to the encrypted file.
Replace <output_file> with the desired name for the decrypted file.
Replace <password> with the password.


### Example:

To encrypt a file named secret.txt and save the encrypted output as secret_encrypted.txt, use the following command:

```bash
./vencrypt E secret.txt secret_encrypted.txt thestrongpassword123
```

### API Documentation

You can include the ```vencrypt.h``` file in your project and it contains two functions
```c
void encrypt(const char *file1name,const char *file2name,const char *pass);
```
Also
```c
void decrypt(const char *file1name,const char *file2name,const char *pass);
```

This function takes the first parameter as the name of the input file, second parameter as the name of the output file and third as the password. All variables must be constants.

### Limitations:

This implementation uses a simple Caesar cipher-like approach, which is not cryptographically secure for real-world applications.
The maximum password length is set to 30 characters (MAXPASSLEN).

### Contributing:

We welcome contributions to improve vencrypt. Feel free to submit pull requests for bug fixes, enhancements, or security improvements. However, keep in mind the program's educational purpose and the limitations of basic encryption techniques.

### Disclaimer:

The authors and maintainers of this program are not responsible for any misuse or security vulnerabilities arising from its use. For secure file encryption, consider utilizing established cryptographic libraries or algorithms.

