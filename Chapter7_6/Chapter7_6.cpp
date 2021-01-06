#include <iostream>
#include <cstdlib>
#include <ctime>

const int deckSize = 52;
const int playerDeckSize = 13;

enum Suit {clubs, diamonds, hearts, spades};
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card
{
private:
    int m_number;
    Suit m_suit;
public:
    void set(int n, Suit s)
    {
        m_number = n;
        m_suit = s;
    }
    void display() const;
};

void Card::display() const
{
    if (m_number >= 2 && m_number <= 10)
        std::cout << m_number;
    else
    {
        switch (m_number)
        {
            case jack: std::cout << 'J'; break;
            case queen: std::cout << 'Q'; break;
            case king: std::cout << 'K'; break;
            case ace: std::cout << 'A'; break;
        }
    }
    switch (m_suit)
    {
        case clubs: std::cout << "c"; break; //static_cast<char>(5)
        case diamonds: std::cout << "d"; break; //static_cast<char>(4)
        case hearts: std::cout << "h"; break; //static_cast<char>(3)
        case spades: std::cout << "s"; break; //static_cast<char>(6)
    }
}

void printPlayerDeck(Card playerDeck[], const int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        playerDeck[i].display();
        std::cout << " ";
    }
    std::cout << '\n' << '\n';
}

int main()
{

    Card deck[deckSize];
    int j;

    std::cout << '\n';
    for (j = 0; j < deckSize; j++)
    {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }

    srand(std::time(NULL));
    for (j = 0; j < deckSize; j++)
    {
        int k = rand() % deckSize;
        Card temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
    std::cout << "\nShuffled deck: \n";
    for (j = 0; j < deckSize; j++)
    {
        deck[j].display();
        std::cout << " ";
        if (!((j + 1) % 13))
            std::cout << '\n';
    }
    
    std::cout << '\n';

    Card player1[playerDeckSize], player2[playerDeckSize], player3[playerDeckSize], player4[playerDeckSize];
    int a = 0, b = 0, c = 0, d = 0;
    for (j = 0; j < deckSize; j++)
    {
        if (j % 4 == 0)
            player1[a++] = deck[j];
        if (j % 4 == 1)
            player2[b++] = deck[j];
        if (j % 4 == 2)
            player3[c++] = deck[j];
        if (j % 4 == 3)
            player4[d++] = deck[j];
    }

    std::cout << "Player 1: \n";
    printPlayerDeck(player1, playerDeckSize);

    std::cout << "Player 2: \n";
    printPlayerDeck(player2, playerDeckSize);

    std::cout << "Player 3: \n";
    printPlayerDeck(player3, playerDeckSize);

    std::cout << "Player 4: \n";
    printPlayerDeck(player4, playerDeckSize);

}

