#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEXAGRAMS 64

int get_random_hexagram();
const char *fetch_iching_text( int );

int iching_hexagram[ HEXAGRAMS ]; 

int main( int argc, char *argv[] ) {
    int hexagram;
    if ( argc == 2 ) {
        hexagram = atoi( argv[1] ); 
    } else {
        hexagram = get_random_hexagram();
    }
    const char *hexagram_text = fetch_iching_text( hexagram ); 
    if ( hexagram > 0 && hexagram < 65 ) {
        printf("%d %s\n", hexagram, hexagram_text);
    } else {
        fprintf(stderr, "Invalid input. Exiting.\n");
        exit( EXIT_FAILURE );
    }
}

int get_random_hexagram() {
    srand( time( NULL ));
    int hexagram = rand() % 64 + 1;
    return hexagram;
}

const char *fetch_iching_text( int hexagram ) {
    const char *iching_text;
    switch( hexagram ) {
        case 1:
            iching_text = "Force (qian) - The Creative";
            break;
        case 2:
            iching_text = "Field (kun) - The Receptive";
            break;
        case 3:
            iching_text = "Sprouting (zhun) - Difficulty at the Beginning"; 
            break;
        case 4:
            iching_text = "Enveloping (meng) - Youthful Folly";
            break;
        case 5:
            iching_text = "Attending (xu) - Waiting";
            break;
        case 6:
            iching_text = "Arguing (song) - Conflict";
            break;
        case 7:
            iching_text = "Leading (shi) - The Army"; 
            break;
        case 8:
            iching_text = "Grouping (bi) - Holding Together";
            break;
        case 9:
            iching_text = "Small Accumulating (xiao chu) - Small Taming";
            break;
        case 10:
            iching_text = "Treading (lu) - Treading (Conduct) - Continuing with Alertness"; 
            break;
        case 11:
            iching_text = "Pervading (tal) - Peace"; 
            break;
        case 12:
            iching_text = "Obstruction (pi) - Standstill";
            break;
        case 13:
            iching_text = "Concording Peoople (tong ren) - Fellowship";
            break;
        case 14:
            iching_text = "Great Possessing (da you) - Great Possession - Independence, Freedom";
            break;
        case 15:
            iching_text = "Humbling (qian) - Modesty - Being Reserved, Refraining";
            break;
        case 16:
            iching_text = "Providing-For (yu) - Enthusiasm - Inducement, New Stimulus";
            break;
        case 17:
            iching_text = "Following (sui) - Following";
            break;
        case 18:
            iching_text = "Corrupting (gu) - Work on the Decayed - Repairing";
            break;
        case 19:
            iching_text = "Nearing (lin) - Approach - Approaching Goal, Arriving";
            break;
        case 20:
            iching_text = "Viewing (guan) - Contemplation - The Withholding";
            break;
        case 21:
            iching_text = "Gnawing Bite (shi ke) - Biting Through - Deciding";
            break;
        case 22:
            iching_text = "Adorning (bi) - Grace - Embellishing";
            break;
        case 23:
            iching_text = "Stripping (bo) - Splitting Apart - Stripping, Flaying"; 
            break;
        case 24:
            iching_text = "Returning (fu) - Return";
            break;
        case 25:
            iching_text = "Without Embroiling (wu wang) - Innocence - Without Rashness";
            break;
        case 26:
            iching_text = "Great Accumulating (da chu) - Great Taming - Accumulating Wisdom";
            break;
        case 27:
            iching_text = "Swallowing (yi) - Mouth Corners - Seeking Nourishment";
            break;
        case 28:
            iching_text = "Great Exceeding (da guo) - Great Preponderance - Great Surpassing";
            break;
        case 29:
            iching_text = "Gorge (kan) - The Abysmal Water - Darkness, Gorge";
            break;
        case 30:
            iching_text = "Radiance (li) - The Clinging - Clinging, Attachment";
            break;
        case 31:
            iching_text = "Conjoining (xian) - Influence - Attraction";
            break;
        case 32:
            iching_text = "Persevering (heng) - Duration - Persevearance";
            break;
        case 33:
            iching_text = "Retiring (dun) - Retreat - Withdrawing";
            break;
        case 34:
            iching_text = "Great Invigorating (da zhuang) - Great Power - Great Boldness";
            break;
        case 35:
            iching_text = "Prospering (jin) - Progress - Expansion, Promotion";
            break;
        case 36:
            iching_text = "Brightness Hiding (ming yi) - Darkening of the Light - Brilliance Injured";
            break;
        case 37:
            iching_text = "Dwelling People (jia ren) - The Family";
            break;
        case 38:
            iching_text = "Polarising (kui) - Opposition - Division, Divergence";
            break;
        case 39:
            iching_text = "Limping (jian) - Obstruction - Halting, Hardship";
            break;
        case 40:
            iching_text = "Taking-Apart (xie) - Deliverance - Liberation, Solution";
            break;
        case 41:
            iching_text = "Diminishing (sun) - Decrease"; 
            break;
        case 42:
            iching_text = "Augmenting (yi) - Increase - Increase";
            break;
        case 43:
            iching_text = "Parting (guai) - Breakthrough - Separation";
            break;
        case 44:
            iching_text = "Coupling (gou) - Coming to Meet - Encountering";
            break;
        case 45:
            iching_text = "Clustering (cui) - Gathering Together - Association, Companionship";
            break;
        case 46:
            iching_text = "Ascending (sheng) - Pushing Upward";
            break;
        case 47:
            iching_text = "Confining (kun) - Oppresion - Exhaustion";
            break;
        case 48:
            iching_text = "Welling (jing) - The Well - Repleneshing, Renewal";
            break;
        case 49:
            iching_text = "Skinning (ge) - Revolution - Abolishing the Old"; 
            break;
        case 50:
            iching_text = "Holding (ding) - The Cauldron - Establishing the New";
            break;
        case 51:
            iching_text = "Shake (zhen) - Arousing - Mobilizing";
            break;
        case 52:
            iching_text = "Bound (gen) - The Keeping Still - Immobility";
            break;
        case 53:
            iching_text = "Infiltrating (jian) - Development - Auspicious Outlook, Infiltration";
            break;
        case 54:
            iching_text = "Converting the Maiden (gui mei) - The Marrying Maiden - Marrying";
            break;
        case 55:
            iching_text = "Abounding (feng) - Abundance - Goal Reached, Ambition Achieved";
            break;
        case 56:
            iching_text = "Sojourning (lu) - The Wanderer - Travel"; 
            printf("%d %s\n", hexagram, iching_text);
            system("/usr/bin/display /root/hex_56.png"); 
            break;
        case 57:
            iching_text = "Ground (xun) - The Gentle - Subtle Influence";
            break;
        case 58:
            iching_text = "Open (dui) - The Joyous - Overt Influence"; 
            break;
        case 59:
            iching_text = "Dispersing (huan) - Dispersion - Dispersal";
            break;
        case 60:
            iching_text = "Articulating (jie) - Limitation - Discipline";
            break;
        case 61:
            iching_text = "Centre Confirming (zhong fu) - Inner Truth - Staying Focused, Avoid Misrepresentation"; 
            break;
        case 62:
            iching_text = "Small Exceeding (xiao guo) - Small Preponderance - Small Surpassing"; 
            break;
        case 63:
            iching_text = "Already Fording (ji ji) - After Completion - Completion";
            break;
        case 64:
            iching_text = "Not-Yet Fording (wei ji) - Incompletion";
            break;
        default:
            iching_text = "Invalid input."; 
            break;
    }
    return iching_text;
}
