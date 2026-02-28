Digital Erosion – Local Run Instructions
========================================

Prerequisites
-------------

- Python 3 installed (for a quick static server), or any other static HTTP server.
- Google Calendar API credentials configured in `art.js`:
  - Replace `GCAL_API_KEY` and `GCAL_CLIENT_ID` with your values from Google Cloud Console.
  - Enable the "Google Calendar API" for your project.
  - Add your local origin (e.g. `http://localhost:8000`) to the OAuth client's "Authorized JavaScript origins".

How to run locally
------------------

1. Open a terminal and navigate to this folder:

   ```bash
   cd "/Users/adamhacker/Documents/DESINV 23/digital-erosion"
   ```

2. Start a simple HTTP server (Python example):

   ```bash
   python3 -m http.server 8000
   ```

   This will serve everything in this directory at `http://localhost:8000`.

3. In Chrome (recommended for Web Serial), open:

   - `http://localhost:8000`

4. Connect the Arduino:

   - Click the "Click me to connect to your Arduino!" button rendered by the sketch.
   - Select your Arduino's serial port when prompted.

5. Sign in to Google (Calendar):

   - When the Google sign-in popup appears, authenticate with the account you want to read calendar events from.
   - The sketch will then fetch today's busy hours from your primary calendar and drive the visual pulse.

