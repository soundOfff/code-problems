#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define int long long

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vi people(n);
    vi ice_shops(m);

    for (int i = 0; i < n; ++i)
    {
        cin >> people[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> ice_shops[i];
    }

    sort(ice_shops.begin(), ice_shops.end());

    int max_customers = 0;

    for (int i = 0; i < n; ++i)
    {
        int hut_position = i * 100 + 1;

        // Find the nearest ice cream shop on the left
        auto left_it = lower_bound(ice_shops.begin(), ice_shops.end(), hut_position);
        int left_distance = (left_it == ice_shops.begin()) ? LLONG_MAX : hut_position - *(--left_it);

        // Find the nearest ice cream shop on the right
        auto right_it = upper_bound(ice_shops.begin(), ice_shops.end(), hut_position);
        int right_distance = (right_it == ice_shops.end()) ? LLONG_MAX : *right_it - hut_position;

        // Determine the max distance we can attract this hut's people
        int distance_to_place_new_shop = min(left_distance, right_distance);

        // Add all people from this hut if we can attract them
        if (distance_to_place_new_shop < min(left_distance, right_distance))
        {
            max_customers += people[i];
        }
    }

    cout << max_customers << endl;

    return 0;
}
