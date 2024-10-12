                                    Daily Press News Reader and Key Decryption Program
This project is designed to simulate a news reading system that retrieves news, tracks which articles have been read, and decrypts hidden keys using magic numbers from the news texts. The keys are hidden in the text using a specific formula that calculates them from magic numbers placed within the articles. The system keeps track of which news items have been read and maintains this information across multiple sessions by storing it in a file.

                                    Features
1. List and Read News Headlines

The program lists the headlines of 4 daily news articles. The user can select any of the news items to read the full content.
If a news item has already been read, the program notifies the user and asks if they want to read it again.

2. Track Read News

The program keeps track of which news articles have been read and saves this information to a file (readed_news_id.txt).
When the program is reopened, it remembers which articles have already been read, ensuring they are not duplicated in the read list.

3. Decrypt Hidden Keys Using Magic Numbers

The news contains hidden magic numbers marked by a # symbol.
The program decrypts these magic numbers using a specific mathematical formula and calculates a key:


                                    Menu Options
The program presents the following menu options:

a: Read a news article.
The user selects a news article to read. If the article has been read before, the program asks if the user wants to read it again.

b: List all read news.
Displays a list of news articles that have already been read.

c: Decrypt a hidden key from a news article.
The user selects a news article, and the program calculates the secret key based on the magic numbers in the article.

y/n: Continue or exit the program.
