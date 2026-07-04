/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Khởi tạo node giả để xây dựng danh sách kết quả
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0; // Biến nhớ

        // Duyệt cho đến khi đi hết cả 2 danh sách và không còn biến nhớ
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Lấy giá trị nhớ từ bước trước

            // Nếu l1 còn phần tử, cộng giá trị vào sum và dịch con trỏ
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Nếu l2 còn phần tử, cộng giá trị vào sum và dịch con trỏ
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Tính toán biến nhớ mới (0 hoặc 1)
            
            // Tạo node mới chứa chữ số hàng đơn vị của sum
            curr->next = new ListNode(sum % 10);
            curr = curr->next; // Dịch con trỏ kết quả tiến lên
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Giải phóng bộ nhớ của node giả để tránh memory leak
        return result;
    }
};