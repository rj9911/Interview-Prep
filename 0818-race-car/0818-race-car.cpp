class Solution {
public:
    bool isValid(int pos,int target){
        return (pos > 0 and pos < target*2);
    }
    
    // shortest sequence -- so to find this we use BFS(standard)
    int racecar(int target) 
    {
        queue<pair<int,int>>q;
        unordered_set<string>vis;
        
        q.push({0,1}); // pos, speed
        vis.insert(to_string(0)+" "+to_string(1));
            
        int steps=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                
                int pos = cur.first;
                int speed = cur.second;
                if(pos == target) 
                    return steps;
                
                // accelerate instruction
                int new_pos = pos+speed;
                int new_speed = speed*2;
                if(vis.find(to_string(new_pos)+" "+to_string(new_speed)) == vis.end() and isValid(new_pos,target))
                {
                    q.push({new_pos, new_speed});
                    vis.insert(to_string(new_pos)+" "+to_string(new_speed));
                }
                
                // reverse instruction
                new_pos = pos;
                new_speed = (speed > 0) ? -1 : 1;
                if(vis.find(to_string(new_pos)+" "+to_string(new_speed)) == vis.end() and isValid(new_pos,target))
                {
                    q.push({new_pos, new_speed});
                    vis.insert(to_string(new_pos)+" "+to_string(new_speed));
                }
                
            }
            steps++;
        }
        return -1;
    }

};