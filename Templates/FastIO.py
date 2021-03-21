import io, os, time


# Function to take normal input
def normal_io():
    # Stores the start time
    start = time.perf_counter()

    # Take Input
    s = input().strip();

    # Stores the end time
    end = time.perf_counter()

    # Print the time taken
    print("\nTime taken in Normal I / O:",
          end - start)


# Function for Fast Input
def fast_io():
    # Reinitialize the Input function
    # to take input from the Byte Like
    # objects
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    # Fast Input / Output
    start = time.perf_counter()

    # Taking input as string
    s = input().decode()

    # Stores the end time
    end = time.perf_counter()

    # Print the time taken
    print("\nTime taken in Fast I / O:",
          end - start)


# Driver Code
if __name__ == "__main__":
    # Function Call
    #normal_io()

    fast_io()