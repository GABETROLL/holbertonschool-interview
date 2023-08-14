#!/usr/bin/python
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
Box 0 is unlocked, and every other box is.

Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes: list[list[int]]) -> bool:
    """
    Each list in 'boxes' represents the list of keys
    in each box,
    and each in in each list represents the index
    of which other box a key present in inside that box should open.

    Returns weather or not ALL OF THE BOXES CAN BE UNLOCKED.
    """

    boxes_opened_status: list[bool] = [False for _ in boxes]
    boxes_opened_status[0] = True

    while True:

        new_boxes_opened_status: list[bool] = boxes_opened_status.copy()

        for box_index, box_is_opened in enumerate(boxes_opened_status):
            if not box_is_opened:
                continue

            # print(box_index, box_is_opened)

            for box_key in boxes[box_index]:
                new_boxes_opened_status[box_key] = True

        if new_boxes_opened_status == boxes_opened_status:
            # No more boxes can be opened.
            break

        boxes_opened_status = new_boxes_opened_status
    
    return all(boxes_opened_status)
