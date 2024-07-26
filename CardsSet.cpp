#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

struct Results{
    string set_name;
    vector<string> selected_cards;
};

int getIdx(string rank){
    int idx;
    if(rank=="10") rank= "T";

    switch(rank[0]){
            case '2': idx = 0; break;
            case '3': idx = 1; break;
            case '4': idx = 2; break;
            case '5': idx = 3; break;
            case '6': idx = 4; break;
            case '7': idx = 5; break;
            case '8': idx = 6; break;
            case '9': idx = 7; break;
            case 'T': idx = 8; break; // Assuming 'T' is used for 10
            case 'J': idx = 9; break;
            case 'Q': idx = 10; break;
            case 'K': idx = 11; break;
            case 'A': idx = 12; break;
            default: idx = -1; // Invalid rank
    }
    return idx;
}

string getRank(int idx){
    switch(idx){
        case 0: return "2";
        case 1: return "3";
        case 2: return "4";
        case 3: return "5";
        case 4: return "6";
        case 5: return "7";
        case 6: return "8";
        case 7: return "9";
        case 8: return "10"; // Note: using "10" for the ten card
        case 9: return "J";
        case 10: return "Q";
        case 11: return "K";
        case 12: return "A";
        default: return ""; // Invalid index
    }
    return "";
}

Results solution(vector<string> &cards){
    Results result;

    vector<int> rank_freq(13, 0);
    for(string card: cards){
        card.pop_back();
        int idx= getIdx(card);
        rank_freq[idx]+= 1;
    }

    vector<string> selected_cards;

    if(cards.size()>=5){
        // set 6
        bool triple= false;
        bool pair= false;
        for(int i=rank_freq.size()-1; i>=0 and (triple==false or pair==false) ;i--){
            if(rank_freq[i]>=3 and triple==false){
                string rank= getRank(i);
                int count= 0;
                for(string card: cards){
                    if(card.substr(0, card.length()-1)==rank){
                        selected_cards.push_back(card);
                        count++;
                        if(count==3) break;
                    }
                }
                triple= true;
            }

            if(rank_freq[i]>=2 and pair==false){
                string rank= getRank(i);
                int count= 0;
                for(string card: cards){
                    if(card.substr(0, card.length()-1)==rank){
                        selected_cards.push_back(card);
                        count++;
                        if(count==2) break;
                    }
                }
                pair= true;
            }
        }
        if(triple and pair){
            result.set_name= "a triple and a pair";
            result.selected_cards= selected_cards;
            return result;
        }
    }
    return result;
}
