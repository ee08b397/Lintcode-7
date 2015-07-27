class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (this->m_pData == object.m_pData) return *this;
        else {
            delete []m_pData;
            if (!object.m_pData) m_pData = 0;
            else {
                m_pData = new char[strlen(object.m_pData) + 1];
                strcpy(m_pData, object.m_pData);
            }
            //int len = strlen(object.m_pData + 1);
        }
        return *this;
    }
};
