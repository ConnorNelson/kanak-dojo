# Data Addresses and Pointers

We only have a finite number of bits, so we can only represent a finite number of things! Fortunately, we can represent a lot of things with a few bits. We can represent 256 different values with 8 bits, or 18,446,744,073,709,551,616 different values with 64 bits. However, bits can go quick! Imagine, for example, an image scheme for storing a 1920 pixel by 1080 pixel image, where each pixel has a red, green, and blue value. We can represent each of those values with 8 bits, so we need 24 bits per pixel. That's 49,766,400 bits for a single image! And what if we wanted to store a video? We'd need 49,766,400 bits for each frame, and if we wanted to store 30 frames per second, we'd need 1,492,992,000 bits per second. An hour long video would take 5,374,771,200,000 bits--5 trillion bits! And we can easily image increasing the resolution, or the frame rate, or the color depth, or the length of the video, or the number of videos. We need a way to store more data than we have bits.

Fortunately, we have tricks! We can imagine that in our hour long video, we might have several frames that are the exact same image. Doesn't it feel like a waste to store multiple copies of the same 49,766,400 bit frame? We can store the frame once, and then reference it by some identifier, such as its *location* or *address* in all of those bits. We can then store a list of identifiers, and we can use that list to reconstruct the video. This is the idea behind **pointers**: they are values that *point* to some other value! And remember, we can represent a value using some bits!