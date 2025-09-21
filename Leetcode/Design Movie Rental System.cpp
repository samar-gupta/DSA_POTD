//Leetcode Link : https://leetcode.com/problems/design-movie-rental-system/

// Approach (Set for ordered storage, Unordered Map for quick lookup)
// T.C. : 
// MovieRentingSystem() -> O(n log n) for n entries (insert each entry into sets)
// search(movie)        -> O(5) i.e. constant. We access the movie set in O(1) from map and then return first 5 elements
// rent(shop, movie)    -> O(log m + log r) per operation
//                         (log m to erase from available[movie], log r to insert into rented, r = total rented movies)
// drop(shop, movie)    -> O(log m + log r) per operation
// report()             -> O(5) i.e. constant

// S.C. : 
// O(n + r) total
// available          -> O(n) (sum of all available movies)
// movieToShopPrice   -> O(n) (sum of all shop-price pairs)
// rented             -> O(r) (r = total rented movies)
class MovieRentingSystem {
class MovieRentingSystem {
public:
    typedef pair<int, int> P;

    unordered_map<int, set<P>> available; //movei -> set<{price, shop}>
    unordered_map<int, set<P>> movieToShopPrice; //movie -> set<shop, price>
    set<tuple<int, int, int>> rented; //{price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            available[movie].insert({price, shop}); //log(n)
            movieToShopPrice[movie].insert({shop, price}); //log(n)
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        if(available.count(movie)) { //O(1)
            for(auto &[_, shop] : available[movie]) { //O(5)
                result.push_back(shop);
                count++;
                if(count >= 5)
                    break;
            }
        }

        return result;
    }
    
    void rent(int shop, int movie) {
        auto it   = movieToShopPrice[movie].lower_bound({shop, INT_MIN}); //log(n)
        int price = it->second;

        available[movie].erase({price, shop}); //log(n)
        rented.insert({price, shop, movie}); //log(n)
    }
    
    void drop(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;

        for(auto &[price, shop, movie] : rented) { //O(5)
            result.push_back({shop, movie});
            count++;
            if(count >= 5)
                break;
        }

        return result;
    }
};
