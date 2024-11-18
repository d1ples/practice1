#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>
#include <vector>
#include <tuple>

constexpr int CardDeckSize = 52;
constexpr int BlackjackPoint = 21;
constexpr int DealerLimit = 17;

enum class CardSuit {
    clubs,
    diamons,
    hearts,
    spades,
    max_value,
};

enum class CardRank {
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,
    max_value,
};

struct Card {
    CardSuit suit; //Declaration of anonymous class must be a definition
    CardRank rank;
};

using CardDeck = std::array<Card,CardDeckSize>;

void printCard(const Card card) {
    switch (card.rank) {

    case CardRank::rank_2:
    case CardRank::rank_3:
    case CardRank::rank_4:
    case CardRank::rank_5:
    case CardRank::rank_6:
    case CardRank::rank_7:
    case CardRank::rank_8:
    case CardRank::rank_9:
    case CardRank::rank_10:
        std::cout << static_cast<int>(card.rank)+2;
        break;
    case CardRank::rank_jack:
        std::cout << "J";
        break;
    case CardRank::rank_queen:
        std::cout << "Q";
        break;
    case CardRank::rank_king:
        std::cout << "K";
        break;
    case CardRank::rank_ace:
        std::cout << "A";
        break;
    default:
        break;
        
    }

    switch (card.suit) {

    case CardSuit::clubs:
        std::cout << "C";
        break;
    case CardSuit::diamons:
        std::cout << "D";
        break;
    case CardSuit::hearts:
        std::cout << "H";
        break;
    case CardSuit::spades:
        std::cout << "S";
        break;
    case CardSuit::max_value:
      break;
    }

    std::cout << ' ';
}

CardDeck createDeck() {

    CardDeck cards;
    CardDeck::size_type cards_iteration = 0;

    for(
        int suit = 0;
        suit < static_cast<int>(CardSuit::max_value);
        ++suit
    ) {
        for (
            int rank = 0;
            rank < static_cast<int>(CardRank::max_value);
            ++rank
        ) {
            cards[cards_iteration].rank = static_cast<CardRank>(rank);
            cards[cards_iteration].suit = static_cast<CardSuit>(suit);

            ++cards_iteration;
        }
    }
    
    return cards;
}

void shuffleDeck(CardDeck& deck) {
    static std::mt19937 mt = static_cast<std::mt19937>(std::time(nullptr));

    std::shuffle(deck.begin(), deck.end(), mt);
}

void printDeck(CardDeck deck) {
    for (Card& card : deck) {
        printCard(card);
    }
}

int getCardValue(Card& card) {

    switch (card.rank) {
    case CardRank::rank_2:
        return 2;
    case CardRank::rank_3:
        return 3;
    case CardRank::rank_4:
        return 4;
    case CardRank::rank_5:
        return 5;
    case CardRank::rank_6:
        return 6;
    case CardRank::rank_7:
        return 7;
    case CardRank::rank_8:
        return 8;
    case CardRank::rank_9:
        return 9;
    case CardRank::rank_10:
    case CardRank::rank_jack:
    case CardRank::rank_queen:
    case CardRank::rank_king:
        return 10;
    case CardRank::rank_ace:
        return 11;
    case CardRank::max_value:
        return 0;
      break;
    }

}

bool playBlackJack(CardDeck& deck) {
    using DealerDeck = std::vector<Card>;
    using PlayerDeck = std::vector<Card>;

    int deckPosition = 0;
    
    DealerDeck dealerDeck = std::vector<Card>();
    int dealerDeckValue = 0;
    int dealerAces = 0;

    PlayerDeck playerDeck = std::vector<Card>();
    int playerDeckValue = 0;
    int playerAces = 0;
    
    // Play

    bool players_move = true;

    dealerDeck.push_back(deck[deckPosition++]);
    if(dealerDeck.back().rank == CardRank::rank_ace)
        dealerAces++;

    playerDeck.push_back(deck[deckPosition++]);
    if(playerDeck.back().rank == CardRank::rank_ace)
        playerAces++;
    playerDeck.push_back(deck[deckPosition++]);
    if(playerDeck.back().rank == CardRank::rank_ace)
        playerAces++;

    // Count and print dealers deck
    std::cout << ">> ";
    for(Card& card : dealerDeck) {
        dealerDeckValue += getCardValue(card);
        printCard(card);
    }
    std::cout << "\nDealer " << dealerDeckValue << " \n\n";
    

    // Count players deck
    for(Card& card : playerDeck) {
        playerDeckValue += getCardValue(card);
    }

    while((playerDeckValue < BlackjackPoint || playerAces > 0) && players_move) {
        if(playerDeckValue == BlackjackPoint) break;

        if(playerDeckValue > BlackjackPoint && playerAces > 0) {
            playerDeckValue -= 10;
            playerAces--;
        }

        std::cout << ">> ";

        for(Card& card : playerDeck) {
            printCard(card);
        }

        std::cout << "\nPlayer " << playerDeckValue << " \n\n";

        std::cout << "(H)it/(S)tand: ";
        char decision;

        do {
            std::cin >> decision;
        } while(
            decision != 'h' &&
            decision != 's' &&
            decision != 'H' &&
            decision != 'S'
        );

        switch (decision) {
            case 'h':
            case 'H':
                playerDeck.push_back(deck[deckPosition++]);
                playerDeckValue += getCardValue(playerDeck.back());
                if(playerDeck.back().rank == CardRank::rank_ace)
                    playerAces++;

                break;
            case 's':
            case 'S':
                players_move = false;
                break;
        }

    }

    std::cout << ">> ";

    for(Card& card : playerDeck) {
        printCard(card);
    }

    std::cout << "\nPlayer " << playerDeckValue << " \n\n";

    if(players_move && playerDeckValue == BlackjackPoint)
        return true;

    if(players_move && playerDeckValue > BlackjackPoint)
        return false;

    std::cout << "\n--- Dealer turn\n";

    while (dealerDeckValue < DealerLimit || dealerAces > 0) {
        if(dealerDeckValue == BlackjackPoint) break;
        
        if(dealerDeckValue > BlackjackPoint && dealerAces > 0) {
            dealerDeckValue -= 10;
            dealerAces--;
        }

        std::cout << ">> ";
        for(Card& card : dealerDeck) {
            printCard(card);
        }
        std::cout << "\nDealer " << dealerDeckValue << " \n\n";

        dealerDeck.push_back(deck[deckPosition++]);
        dealerDeckValue += getCardValue(dealerDeck.back());
        if(dealerDeck.back().rank == CardRank::rank_ace)
            dealerAces++;
    }

    std::cout << ">> ";
    for(Card& card : dealerDeck) {
        printCard(card);
    }
    std::cout << "\nDealer " << dealerDeckValue << " \n\n";


    if(dealerDeckValue == BlackjackPoint)
        return false;

    if(dealerDeckValue > BlackjackPoint)
        return true;
    
    return dealerDeckValue < playerDeckValue;
}

int main() {
    auto cards = createDeck();

    // printDeck(cards);

    // std::cout << "\n--- \n";

    shuffleDeck(cards);

    // printDeck(cards);

    if(playBlackJack(cards)) {
        std::cout << "Player won!";
        return 0;
    }

    std::cout << "Player loose!";
    return 0;
}
