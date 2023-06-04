#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 12

int main()
{
    int pages[MAX_PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames with -1 (empty)
    int pageFaults = 0;
    int frameIndex = 0; // Index to keep track of the next frame to be replaced

    for (int i = 0; i < MAX_PAGES; i++)
    {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j] == page)
            {
                found = 1;
                break;
            }
        }

        // If page not found, replace the oldest page (FIFO)
        if (found == 0)
        {
            frames[frameIndex] = page;                  // Replace the page at the current frameIndex
            frameIndex = (frameIndex + 1) % MAX_FRAMES; // Increment the frameIndex (wrap around if needed) (Modulo to find remainder)
            pageFaults++;
        }

        // Print the current state of frames after each page reference
        printf("Page %d: ", page);
        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
