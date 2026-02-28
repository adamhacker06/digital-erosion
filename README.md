# Digital Erosion

A browser-based interactive piece that ties your calendar’s busyness and a physical potentiometer to a visual pulse—chaos and calm driven by your day and your hand.

## Showcase & Description

### Prelude

Digital Erosion reflects how schedule density and small physical adjustments shape our sense of control. The sketch reads how many hours are marked busy today on your Google Calendar and combines that with a potentiometer on an Arduino. The result is a live visual pulse: more busy hours push the piece toward chaos, while turning the knob lets you search for a fleeting “calm” state—a sweet spot that slowly drifts so the search never quite ends.

### Concept

- **Calendar as input**: The piece fetches today’s busy hours from your primary Google Calendar. More blocked time increases a baseline level of visual chaos.
- **Potentiometer as control**: An Arduino sends a potentiometer value (0–1023) over Web Serial. The knob does not simply map to “calm at one end”; instead there is a hidden **sweet spot** that changes each time you load the sketch.
- **Finding calm**: You turn the knob to find the calm zone. When you hold it there long enough, the sweet spot slowly drifts, so you have to keep adjusting—a meditative, never-stable balance.
- **Visual pulse**: A central form responds to both calendar load and knob position: chaos when the day is busy or the knob is far from the sweet spot, and a calmer state when you find (and briefly hold) the calm zone.

### Running the piece

**Prerequisites**

- **Python 3** (or any static HTTP server) for serving the project locally.
- **Google Calendar API** credentials in `art.js` when using live calendar data:
  - Replace `GCAL_API_KEY` and `GCAL_CLIENT_ID` with your values from [Google Cloud Console](https://console.cloud.google.com/).
  - Enable the **Google Calendar API** for your project.
  - Add your local origin (e.g. `http://localhost:8000`) to the OAuth client’s **Authorized JavaScript origins**.
- **Chrome** is recommended (Web Serial support).

**Steps**

1. Open a terminal and go to the project folder:

   ```bash
   cd "/Users/adamhacker/Documents/DESINV 23/digital-erosion"
   ```

2. Start a local HTTP server (e.g. Python):

   ```bash
   python3 -m http.server 8000
   ```

   The project is served at `http://localhost:8000`.

3. In Chrome, open `http://localhost:8000`.

4. **Connect the Arduino**: Click **“Click me to connect to your Arduino!”** and choose your board’s serial port when prompted.

5. **Sign in to Google** (if using live calendar): When the sign-in popup appears, sign in with the account whose calendar should drive the visual. The sketch then uses today’s busy hours to drive the pulse.

To run without credentials, set `USE_FAKE_CALENDAR_DATA = true` in `art.js` and adjust `FAKE_BUSY_HOURS` to simulate a busier or calmer day.

### Controls / interaction

- **Potentiometer**: Turn the knob to search for the calm sweet spot. Holding it there causes the sweet spot to drift so you must keep adjusting.
- **Button**: “Click me to connect to your Arduino!” opens the Web Serial port picker to connect the Arduino once per session.

There is no other UI; the only inputs are the knob and the calendar data.

### Technical notes

- **Stack**: p5.js in the browser, [Makeability Lab Serial library](https://github.com/makeabilitylab/p5js) for Web Serial, Google Calendar API (optional).
- **Arduino**: Sends the potentiometer value over serial at 115200 baud. Use the `serial_input` sketch in `serial_input/serial_input.ino` for the expected behavior.
- **Calendar**: With `USE_FAKE_CALENDAR_DATA = false`, the page uses the Google API client to list today’s events and sums busy time; that value is normalized and combined with the normalized pot value to drive the chaos/calm model.
- **Sweet spot**: Each run picks a random `calmPotCenter` (0–1). The sketch measures how close the normalized pot value is to that center and applies a falloff (e.g. `pow(1.0 - normalizedDistance, 1.4)`). After a short hold in the calm zone, `calmPotCenter` drifts so the viewer must keep searching.

## Process

### Setup and dependencies

- **Arduino**: Flash `serial_input/serial_input.ino` so the board reads the potentiometer and streams the value over serial.
- **Credentials**: For live calendar, create OAuth credentials in Google Cloud Console, enable the Calendar API, and set authorized JavaScript origins to your local URL (e.g. `http://localhost:8000`). Put the API key and client ID into `art.js` as described in *Running the piece*.
- **Fake data**: With `USE_FAKE_CALENDAR_DATA = true`, no Google sign-in or credentials are required; the sketch uses `FAKE_BUSY_HOURS` for the calendar input.

## Conclusion & Reflection

Digital Erosion ties two inputs—schedule density and a single physical control—into one continuous feedback loop. The drifting sweet spot makes “calm” something you chase rather than lock in, reflecting how both busy days and attention constantly shift.
