# CONTRIBUTING

> Lightweight rules for a 6-person student team. Keep it practical — no bureaucracy.

## Golden Rules

1. **Don't delete important research.** If something is no longer relevant, move it to `04_INITIAL_IDEA_RESEARCH/` instead of deleting it. Research is the team's memory.
2. **Keep research sources documented.** When you add research, note where the information came from (link, paper, source name). Unverifiable claims hurt us in front of judges.
3. **Use meaningful filenames.** `WORKSPACE/thermal_management_papers.md` beats `notes2.md`. Follow [`NAMING_CONVENTIONS.md`](./NAMING_CONVENTIONS.md).
4. **Avoid random duplicate files.** Before creating a file, check if the content already exists somewhere. Link to it instead of copying it.
5. **Discuss major architecture changes.** If a change affects both projects or the shared tech (`03_SHARED_TECH/`), discuss it with the team first.
6. **Record important decisions.** Any decision that shapes a project goes in `00_TEAM_WORKSPACE/DECISIONS/` as `DECISION_XXX_...md`. See the template there.
7. **Keep commits meaningful.** One logical change per commit, clear message. Format: `type(scope): description` (e.g., `docs(idea2): add thermal research notes`).

## Where Things Go

| Content | Location |
|---|---|
| Project research/design/docs | Your project workspace (`01_...` or `02_...`) |
| Team-wide strategy/methodology | `00_TEAM_WORKSPACE/SHARED_RESOURCES/` |
| Decisions | `00_TEAM_WORKSPACE/DECISIONS/` |
| Meeting notes | `00_TEAM_WORKSPACE/MEETING_NOTES/` |
| Shared hardware/tech | `03_SHARED_TECH/` |
| Historical/archived research | `04_INITIAL_IDEA_RESEARCH/` |

## Working on a Project

1. Read `00_CURRENT_STATUS.md` — know the phase.
2. Read your project's README — know the structure.
3. Add research/docs in the right numbered folder.
4. Record any decisions you make.
5. Commit with a meaningful message.

## Reviewing

- Before merging anything that changes structure or architecture, get a quick sanity check from the other squad.
- Keep reviews lightweight — this is a hackathon team, not an enterprise.