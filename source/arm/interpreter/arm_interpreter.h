

#ifndef _ARM_INTERPRETER_H
#define _ARM_INTERPRETER_H

#include "Common.h"

#include "arm/arm_interface.h"
#include "arm/skyeye_common/armdefs.h"
#include "arm/skyeye_common/armemu.h"

class ARM_Interpreter final : virtual public ARM_Interface {
public:

    ARM_Interpreter();
    ~ARM_Interpreter();

    /**
     * Set the Program Counter to an address
     * @param pc Address to set PC to
     */
    void SetPC(u32 pc) override;

    /*
     * Get the current Program Counter
     * @return Returns current PC
     */
    u32 GetPC() const override;

    /**
     * Get an ARM register
     * @param index Register index (0-15)
     * @return Returns the value in the register
     */
    u32 GetReg(int index) const override;

    /**
     * Set an ARM register
     * @param index Register index (0-15)
     * @param value Value to set register to
     */
    void SetReg(int index, u32 value) override;

    /**
     * Get the current CPSR register
     * @return Returns the value of the CPSR register
     */
    u32 GetCPSR() const override;

    /**
     * Set the current CPSR register
     * @param cpsr Value to set CPSR to
     */
    void SetCPSR(u32 cpsr) override;

    /**
     * Returns the number of clock ticks since the last reset
     * @return Returns number of clock ticks
     */
    u64 GetTicks() const override;

    /**
    * Advance the CPU core by the specified number of ticks (e.g. to simulate CPU execution time)
    * @param ticks Number of ticks to advance the CPU core
    */
    void AddTicks(u64 ticks) override;

    /**
     * Saves the current CPU context
     * @param ctx Thread context to save
     */
    void SaveContext(ThreadContext& ctx) override;

    /**
     * Loads a CPU context
     * @param ctx Thread context to load
     */
    void LoadContext(const ThreadContext& ctx) override;

    /// Prepare core for thread reschedule (if needed to correctly handle state)
    void PrepareReschedule() override;
    ARMul_State* state;

protected:

    /**
     * Executes the given number of instructions
     * @param num_instructions Number of instructions to executes
     */
    u64 ExecuteInstructions(int num_instructions) override;


};
#endif
